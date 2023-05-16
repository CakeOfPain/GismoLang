use std::{net::TcpStream, slice::Iter, process::{Command, Stdio}, io::{Read, Write}};

pub fn handle_middleware(
    mut stream: TcpStream,
    path: String,
    request_line: &String,
    request_line_vec: Vec<&str>,
    lines_iter: Iter<String>,
) {
    // Call Gismo Module
    let mut command: Command;

    if path.ends_with("/") {
        command = Command::new(format!("./web{path}index"));
    } else {
        command = Command::new(format!("./web{path}/index"));
    }

    command.arg(format!("Method={}", request_line_vec.get(0).unwrap()));
    command.arg(format!("Request-Line={request_line}"));
    command.stdout(Stdio::piped());
    command.stderr(Stdio::piped());

    for x in lines_iter {
        println!("{}", x);
        command.arg(x.replace(": ", "="));
    }

    let mut child = command.spawn().expect("Failed to execute middleware!");
    let mut stdout = child.stdout.take().unwrap();
    let mut stderr = child.stderr.take().unwrap();
    let mut result = String::new();
    let mut result_error = String::new();
    stdout.read_to_string(&mut result).unwrap();
    stderr.read_to_string(&mut result_error).unwrap();

    child.wait().expect("Failed to wait for middleware!");

    if result_error != "" {
        stream.write_all(format!("HTTP/1.0 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n<h1>OOPS!</h1><p>{result_error}</p>").as_bytes()).unwrap();
    } else {
        stream
            .write_all(format!("{result_error}{result}").as_bytes())
            .unwrap();
    }
}
