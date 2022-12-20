use std::{
    env,
    fs::{self, File},
    io::Read,
};

use virtual_machine::GismoVirtualMachine;

mod bytecode;
mod bytereader;
mod virtual_machine;

fn main() {
    let mut breakpoints: Vec<String> = vec![];

    let args: Vec<String> = env::args().collect();

    let mut arg_count = 1;
    for arg in args[1..].iter() {
        if !arg.starts_with("-bp=") {
            break;
        }

        let label = &arg[4..];

        breakpoints.push(label.to_string());
        arg_count+=1;
    }

    let filename = args
        .get(arg_count)
        .expect("GVM: [Argument error] No file to execute was provided!");

    
    let mut file =
        File::open(filename).expect("GVM: [File error] File was not found or couldn't be open!");
    
    let metadata = fs::metadata(filename).expect("GVM: [File error] Unable to read metadata");
    
    let mut bytecode = vec![0; metadata.len() as usize];
    file.read(&mut bytecode).expect("buffer overflow");

    let mut gvm = GismoVirtualMachine::new(bytecode);
    gvm.set_breakpoints(breakpoints);
    gvm.execute_main();
}
