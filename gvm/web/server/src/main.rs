mod api;
mod gismo;
mod middleware;

use std::{
    env,
    io::{prelude::*, BufReader},
    net::{TcpListener, TcpStream},
    thread,
};

use api::handle_api;
use gismo::handle_gismo;
use middleware::handle_middleware;

fn main() {
    let args: Vec<_> = env::args().collect();
    let addr = args.get(1).unwrap();
    let listener = TcpListener::bind(addr).unwrap();

    for stream in listener.incoming() {
        let stream = stream.unwrap();
        thread::spawn(|| {
            handle_connection(stream);
        });
    }
}

fn handle_connection(mut stream: TcpStream) {
    let buf_reader = BufReader::new(&mut stream);

    let lines: Vec<_> = buf_reader
        .lines()
        .map(|x| x.unwrap())
        .take_while(|x| !x.is_empty())
        .collect();
    let mut lines_iter = lines.iter();
    let request_line = lines_iter.next().unwrap();
    let request_line_vec: Vec<_> = request_line.split(" ").collect();
    let path = request_line_vec.get(1).unwrap().replace("..", ".");

    if path.starts_with("/function/") {
        // Only functions can call functions
        // Call file ..index.gim
        handle_gismo(stream, path, request_line, request_line_vec, lines_iter);
    } else if path.starts_with("/middleware/") {
        // Only functions can call middleware

        // Call file ..index
        handle_middleware(stream, path, request_line, request_line_vec, lines_iter);
    } else if path.starts_with("/api/") {
        // This is public

        // Call file ..index.json
        handle_api(stream, path, request_line, request_line_vec, lines_iter);
    } else {
        // Error!
        stream.write_all(
            format!(
                "HTTP/1.0 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n<h1>OOPS!</h1><p>Not a valid path...</p>"
            ).as_bytes()
        ).unwrap();
    }
}
