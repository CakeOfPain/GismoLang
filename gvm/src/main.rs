use std::{
    fs::{self, File},
    io::Read, env,
};

use virtual_machine::GismoVirtualMachine;

mod bytecode;
mod bytereader;
mod virtual_machine;

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename = args.get(1).expect("GVM: [Argument error] No file to execute was provided!");
    let mut file =
        File::open(filename).expect("GVM: [File error] File was not found or couldn't be open!");
    let metadata = fs::metadata(filename).expect("GVM: [File error] Unable to read metadata");
    let mut bytecode = vec![0; metadata.len() as usize];
    file.read(&mut bytecode).expect("buffer overflow");

    let mut gvm = GismoVirtualMachine::new(bytecode);
    gvm.execute_main();
}
