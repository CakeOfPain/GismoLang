use std::{fs, io::Write, net::TcpStream, slice::Iter};

use crate::{gismo::handle_gismo, middleware::handle_middleware};

pub fn handle_api(
    mut stream: TcpStream,
    path: String,
    request_line: &String,
    request_line_vec: Vec<&str>,
    lines_iter: Iter<String>,
) {
    let raw_yaml: String;

    if path.ends_with("/") {
        raw_yaml = fs::read_to_string(format!("./web{path}index.yml")).unwrap();
    } else {
        raw_yaml = fs::read_to_string(format!("./web{path}/index.yml")).unwrap();
    }

    let yaml = yaml_rust
    let json = json::parse(&raw_json).unwrap();
    handle_path(&json, stream, path, request_line, request_line_vec, lines_iter);
}
