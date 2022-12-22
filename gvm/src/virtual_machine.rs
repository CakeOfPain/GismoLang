use core::panic;
use std::{
    collections::{HashMap, HashSet},
    env,
    fmt::{self},
    fs::File,
    io::{self, BufRead, BufReader, Write},
    process::{self},
    thread,
};

use crate::{
    bytecode::{Bytecode, ConstantCode},
    bytereader::ByteReader,
};

impl fmt::Display for Bytecode {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:?}", self)
    }
}

#[derive(Clone)]
pub enum StackElement {
    Text(GismoText),
    Func(u32),
    Cmplx(Vec<StackElement>),
    Num(u64),
    Nothing,
}

pub fn zip_zack_encode(i: i64) -> i64 {
    (i >> 63) ^ (i << 1)
}

pub fn zip_zack_decode(i: i64) -> i64 {
    (i >> 1) ^ -(i & 1)
}

#[derive(Clone)]
pub struct GismoText {
    base_string: Option<u32>,
    mod_string: Option<Vec<u8>>,
}

impl GismoText {
    pub fn empty() -> Self {
        Self {
            base_string: None,
            mod_string: None,
        }
    }

    pub fn from(text: u32) -> Self {
        Self {
            base_string: Some(text),
            mod_string: None,
        }
    }

    pub fn new(text: String) -> Self {
        Self {
            base_string: None,
            mod_string: Some(text.as_bytes().clone().to_vec()),
        }
    }

    pub fn add_char(&mut self, character: u64, gvm: &GismoVirtualMachine) {
        match (self.base_string, &mut self.mod_string) {
            (None, None) => {
                self.mod_string = Some(vec![character as u8]);
            }
            (_, Some(mod_string)) => mod_string.push(character as u8),
            (Some(base_string), None) => {
                let mut const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                const_text.push(character as u8);
                self.mod_string = Some(const_text);
            }
        }
    }

    pub fn set_char(&mut self, index: u64, character: u64, gvm: &GismoVirtualMachine) {
        match (self.base_string, &mut self.mod_string) {
            (None, None) => {
                panic!("GVM: [TextSetChar] Cannot set character in empty text!")
            }
            (_, Some(mod_string)) => {
                mod_string[index as usize] = character as u8;
            }
            (Some(base_string), None) => {
                let mut const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                const_text[index as usize] = character as u8;
                self.mod_string = Some(const_text);
            }
        }
    }

    pub fn remove_char(&mut self, index: u64, gvm: &GismoVirtualMachine) {
        match (self.base_string, &mut self.mod_string) {
            (None, None) => {
                panic!("GVM: [TextRemoveChar] Cannot remove character from empty text!");
            }
            (_, Some(mod_string)) => {
                mod_string.remove(index as usize);
            }
            (Some(base_string), None) => {
                let mut const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                const_text.remove(index as usize);
                self.mod_string = Some(const_text);
            }
        }
    }

    pub fn pop_char(&mut self, gvm: &GismoVirtualMachine) {
        match (self.base_string, &mut self.mod_string) {
            (None, None) => {
                panic!("GVM: [TextPopChar] Cannot pop character from empty text!");
            }
            (_, Some(mod_string)) => {
                mod_string.pop();
            }
            (Some(base_string), None) => {
                let mut const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                const_text.pop();
                self.mod_string = Some(const_text);
            }
        }
    }

    pub fn get_size(&self, gvm: &GismoVirtualMachine) -> usize {
        match (self.base_string, &self.mod_string) {
            (None, None) => 0,
            (_, Some(mod_string)) => mod_string.len(),
            (Some(base_string), None) => {
                let const_text = gvm.const_texts.get(base_string as usize).unwrap();
                const_text.len()
            }
        }
    }

    pub fn get_char(&self, index: u64, gvm: &GismoVirtualMachine) -> u64 {
        match (self.base_string, &self.mod_string) {
            (None, None) => {
                panic!("GVM: [TextGetChar] Cannot access character from empty text!");
            }
            (_, Some(mod_string)) => mod_string[index as usize] as u64,
            (Some(base_string), None) => {
                let const_text = gvm.const_texts.get(base_string as usize).unwrap();
                const_text[index as usize] as u64
            }
        }
    }

    pub fn to_text(&self, gvm: &GismoVirtualMachine) -> String {
        match (self.base_string, &self.mod_string) {
            (None, None) => String::from(""),
            (_, Some(mod_string)) => String::from_utf8(mod_string.clone()).unwrap(),
            (Some(base_string), None) => {
                let const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                String::from_utf8(const_text).unwrap()
            }
        }
    }

    pub fn get_buffer(&self, gvm: &GismoVirtualMachine) -> Option<Vec<u8>> {
        match (self.base_string, &self.mod_string) {
            (None, None) => None,
            (_, Some(mod_string)) => Some(mod_string.clone()),
            (Some(base_string), None) => {
                Some(gvm.const_texts.get(base_string as usize).unwrap().clone())
            }
        }
    }

    pub fn concat(&mut self, other: &GismoText, gvm: &GismoVirtualMachine) {
        match (self.base_string, &mut self.mod_string) {
            (None, None) => {
                self.mod_string = other.get_buffer(gvm);
            }
            (_, Some(mod_string)) => {
                if let Some(mut other_string) = other.get_buffer(gvm) {
                    mod_string.append(&mut other_string);
                }
            }
            (Some(base_string), None) => {
                let mut const_text = gvm.const_texts.get(base_string as usize).unwrap().clone();
                if let Some(mut other_string) = other.get_buffer(gvm) {
                    const_text.append(&mut other_string);
                }
                self.mod_string = Some(const_text);
            }
        }
    }

    pub fn hash(&self, gvm: &GismoVirtualMachine) -> u64 {
        match (self.base_string, &self.mod_string) {
            (None, None) => 0,
            (_, Some(mod_string)) => mod_string
                .iter()
                .fold(0, |sum, n| sum + n.to_owned() as u64),
            (Some(base_string), None) => {
                let const_text = gvm.const_texts.get(base_string as usize).unwrap();
                const_text
                    .iter()
                    .fold(0, |sum, n| sum + n.to_owned() as u64)
            }
        }
    }
}

#[derive(Clone)]
pub struct GismoFunction {
    const_position: u32,
    local_num8: u32,
    local_num16: u32,
    local_num32: u32,
    local_num64: u32,
    local_functions: u32,
    local_texts: u32,
    local_cmplxs: u32,
    instructions: Vec<u8>,
}

pub struct GismoLocalRegister {
    local_num8: Vec<u8>,
    local_num16: Vec<u16>,
    local_num32: Vec<u32>,
    local_num64: Vec<u64>,
    local_functions: Vec<u32>,
    local_texts: Vec<GismoText>,
    local_cmplxs: Vec<Vec<StackElement>>,
}

impl GismoLocalRegister {
    pub fn from(function: &GismoFunction) -> Self {
        Self {
            local_num8: vec![0; function.local_num8 as usize],
            local_num16: vec![0; function.local_num16 as usize],
            local_num32: vec![0; function.local_num32 as usize],
            local_num64: vec![0; function.local_num64 as usize],
            local_functions: vec![0; function.local_functions as usize],
            local_texts: vec![GismoText::empty(); function.local_texts as usize],
            local_cmplxs: vec![Vec::new(); function.local_cmplxs as usize],
        }
    }
}

pub enum GismoSymbolScope {
    Const,
    Global,
    Local,
}

pub enum GismoSymbolType {
    U1,
    U2,
    U4,
    U8,
    I1,
    I2,
    I4,
    I8,
    Text,
    Cmplx,
    Func,
}

impl GismoSymbolType {
    pub fn from(name: &str) -> Self {
        match name {
            "u1" => GismoSymbolType::U1,
            "u2" => GismoSymbolType::U2,
            "u4" => GismoSymbolType::U4,
            "u8" => GismoSymbolType::U8,
            "i1" => GismoSymbolType::I1,
            "i2" => GismoSymbolType::I2,
            "i4" => GismoSymbolType::I4,
            "i8" => GismoSymbolType::I8,
            "t" => GismoSymbolType::Text,
            "c" => GismoSymbolType::Cmplx,
            "f" => GismoSymbolType::Func,
            _ => panic!("GVM: [Hint] lc/gb/cs: Unknown type def!"),
        }
    }
}

pub struct DebugSymbol {
    name: String,
    type_id: GismoSymbolType,
    scope: GismoSymbolScope,
    index: u32,
}

pub struct Debugger {
    line: u32,
    file: String,
    symbols: HashMap<String, DebugSymbol>,
    breakpoints: HashSet<String>,
}

impl Debugger {
    pub fn new() -> Self {
        Self {
            line: 0,
            file: "[Undefined]".to_string(),
            symbols: HashMap::new(),
            breakpoints: HashSet::new(),
        }
    }

    pub fn set_line(&mut self, line: u32, gvm: &GismoVirtualMachine) {
        self.line = line;
        self.check_breakpoint(gvm);
    }

    pub fn set_file(&mut self, file: String, gvm: &GismoVirtualMachine) {
        self.file = file;
        self.check_breakpoint(gvm);
    }

    fn check_breakpoint(&self, gvm: &GismoVirtualMachine) {
        if gvm.debugger.breakpoints.contains(&self.build_label()) {
            self.debugging(gvm);
        }
    }

    fn build_label(&self) -> String {
        let path = self.file
            .split(":")
            .collect::<Vec<&str>>()
            .get(0)
            .expect("GVM: [Hint] Missing Path.")
            .to_string();
        let label = path + ":" + &self.line.to_string();
        label
    }

    pub fn add_symbol(&mut self, symbol: DebugSymbol) {
        self.symbols.insert(symbol.name.clone(), symbol);
    }

    pub fn add_breakpoint(&mut self, label: String) {
        self.breakpoints.insert(label);
    }

    pub fn debugging(&self, gvm: &GismoVirtualMachine) {
        if self.file.eq("[Undefined]") {
            return;
        }
        println!("\n\n");
        println!("*** Breakpoint ***");
        let path = self
            .file
            .split(":")
            .collect::<Vec<&str>>()
            .get(0)
            .expect("GVM: [Hint] Missing Path.")
            .clone();
        let function = self
            .file
            .split(":")
            .collect::<Vec<&str>>()
            .get(1)
            .expect("GVM: [Hint] bp: Missing Function.")
            .clone();
        println!("At {}:{} Function: {}", path, self.line, function);
        let file = File::open(path);

        if let Ok(file) = file {
            let reader = BufReader::new(file);

            for (line_count, line) in reader.lines().enumerate().filter(|(i, _)| {
                (*i as i64 > (self.line as i64 - 5)) && (*i < (self.line + 5) as usize)
            }) {
                if (line_count + 1) == self.line as usize {
                    println!(
                        "\x1b[0;30;47m{:5}: {}\x1b[0m",
                        line_count + 1,
                        line.unwrap()
                    );
                } else {
                    println!("{:5}: {}", line_count + 1, line.unwrap());
                }
            }
        }
        println!();
        // Command
        let mut command = String::new();

        loop {
            print!("next/help/[cmd]> ");
            io::stdout().flush().unwrap();
            io::stdin().read_line(&mut command).unwrap();
            match &command.to_lowercase() {
                x if x.contains("next") => {
                    break;
                }
                x if x.contains("help") => {}
                x if x.len() < 2 => {
                    break;
                }
                _ => {
                    println!("Use the command 'help' for listing all commands.")
                }
            }
        }
    }
}

pub struct GismoStackFrame {
    function: u32,
    stack_offset: usize,
    local_register: GismoLocalRegister,
    instr_pos: usize,
    argument_count: u32,

    // debugging
    debugger: Debugger,
}

impl GismoStackFrame {
    pub fn from(function: &GismoFunction, offset: usize) -> Self {
        Self {
            function: function.const_position,
            stack_offset: offset,
            local_register: GismoLocalRegister::from(function),
            instr_pos: 0,
            argument_count: 0,

            // debugging
            debugger: Debugger::new(),
        }
    }

    pub fn get_byte_reader<'a>(&'a mut self, gvm: &'a GismoVirtualMachine) -> ByteReader {
        ByteReader::new(
            &gvm.const_functions[self.function as usize].instructions,
            &mut self.instr_pos,
        )
    }
}

pub struct GismoVirtualMachine {
    const_num8_count: u32,
    const_num16_count: u32,
    const_num32_count: u32,
    const_num64_count: u32,
    const_functions_count: u32,
    const_texts_count: u32,

    const_num8: Vec<u8>,
    const_num16: Vec<u16>,
    const_num32: Vec<u32>,
    const_num64: Vec<u64>,
    const_functions: Vec<GismoFunction>,
    const_texts: Vec<Vec<u8>>,

    global_num8: Vec<u8>,
    global_num16: Vec<u16>,
    global_num32: Vec<u32>,
    global_num64: Vec<u64>,
    global_functions: Vec<u32>,
    global_texts: Vec<GismoText>,
    global_cmplxs: Vec<Vec<StackElement>>,

    // debugging
    debugger: Debugger,
}

impl GismoVirtualMachine {
    pub fn new(bytecode: Vec<u8>) -> Self {
        // parsing the bytecode
        let mut instr_pos = 0usize;
        let mut byte_reader = ByteReader::new(&bytecode, &mut instr_pos);

        // Magic
        let magic = byte_reader.read_u32();

        // Magic must be "\0gim" in order to continue
        if magic != 0x0067696D {
            panic!("GVM: [Magic Error] Given wrong Bytecode format!");
        }

        let mut machine = Self {
            const_num8_count: byte_reader.read_u32(),
            const_num16_count: byte_reader.read_u32(),
            const_num32_count: byte_reader.read_u32(),
            const_num64_count: byte_reader.read_u32(),
            const_functions_count: byte_reader.read_u32(),
            const_texts_count: byte_reader.read_u32(),

            const_num8: Vec::new(),
            const_num16: Vec::new(),
            const_num32: Vec::new(),
            const_num64: Vec::new(),
            const_functions: Vec::new(),
            const_texts: Vec::new(),

            global_num8: vec![0; byte_reader.read_u32() as usize],
            global_num16: vec![0; byte_reader.read_u32() as usize],
            global_num32: vec![0; byte_reader.read_u32() as usize],
            global_num64: vec![0; byte_reader.read_u32() as usize],
            global_functions: vec![0; byte_reader.read_u32() as usize],
            global_texts: vec![GismoText::empty(); byte_reader.read_u32() as usize],
            global_cmplxs: vec![Vec::new(); byte_reader.read_u32() as usize],

            debugger: Debugger::new(),
        };

        // Parse Consts
        while byte_reader.has_next() {
            let instr: ConstantCode = ConstantCode::try_from(byte_reader.read_u8())
                .expect("GVM: [Const-Definitions] Unable to parse definition, unknown command.");
            match instr {
                ConstantCode::Nop => {}
                ConstantCode::Num8 => {
                    if !(machine.const_num8.len() < machine.const_num8_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_num8.push(byte_reader.read_u8());
                }
                ConstantCode::Num16 => {
                    if !(machine.const_num16.len() < machine.const_num16_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_num16.push(byte_reader.read_u16());
                }
                ConstantCode::Num32 => {
                    if !(machine.const_num32.len() < machine.const_num32_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_num32.push(byte_reader.read_u32());
                }
                ConstantCode::Num64 => {
                    if !(machine.const_num64.len() < machine.const_num64_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_num64.push(byte_reader.read_u64());
                }
                ConstantCode::Text => {
                    if !(machine.const_texts.len() < machine.const_texts_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_texts.push(byte_reader.read_buffer());
                }
                ConstantCode::Function => {
                    if !(machine.const_functions.len() < machine.const_functions_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_functions.push(GismoFunction {
                        const_position: machine.const_functions.len() as u32,
                        local_num8: byte_reader.read_u32(),
                        local_num16: byte_reader.read_u32(),
                        local_num32: byte_reader.read_u32(),
                        local_num64: byte_reader.read_u32(),
                        local_functions: byte_reader.read_u32(),
                        local_texts: byte_reader.read_u32(),
                        local_cmplxs: byte_reader.read_u32(),
                        instructions: byte_reader.read_buffer(),
                    });
                }
                ConstantCode::Recover => {
                    if !(machine.const_functions.len() < machine.const_functions_count as usize) {
                        panic!("GVM: [Const-Definitions] Const-Index out of Bounds!");
                    }
                    machine.const_functions.push(GismoFunction {
                        const_position: machine.const_functions.len() as u32,
                        local_num8: byte_reader.read_u32(),
                        local_num16: byte_reader.read_u32(),
                        local_num32: byte_reader.read_u32(),
                        local_num64: byte_reader.read_u32(),
                        local_functions: byte_reader.read_u32(),
                        local_texts: byte_reader.read_u32(),
                        local_cmplxs: byte_reader.read_u32(),
                        instructions: byte_reader.read_buffer(),
                    });
                }
            };
        }
        machine
    }

    pub fn set_breakpoints(&mut self, breakpoints: Vec<String>) {
        for label in breakpoints {
            self.debugger.add_breakpoint(label);
        }
    }

    pub fn execute_main(&mut self) {
        let arguments: Vec<String> = env::args().collect();
        self.execute_func(
            0,
            vec![StackElement::Cmplx(
                arguments[1..]
                    .iter()
                    .map(|arg| StackElement::Text(GismoText::new(arg.clone())))
                    .collect(),
            )],
        );
    }

    pub fn execute_func(&mut self, pos: u32, arguments: Vec<StackElement>) {
        thread::scope(|_scope| {
            if self.const_functions.len() < 1 {
                panic!("GVM: [Main-Function] No main-function with index 0 was provided!");
            }

            // Operation Stack
            let mut operation_stack: Vec<StackElement> = arguments;

            // Stack-frames
            let mut stackframes: Vec<GismoStackFrame> = vec![GismoStackFrame::from(
                &self.const_functions[pos as usize],
                operation_stack.len(),
            )];

            /*
             * For recording each time a instruction takes
             */
            // struct GismoRecord {
            //     name: String,
            //     count: usize,
            //     sum: u128
            // }

            // impl GismoRecord {
            //     fn average(&self) -> u128 {
            //         self.sum / self.count as u128
            //     }
            // }

            // let mut instr_monitoring: HashMap<String, GismoRecord> = HashMap::new();

            while !stackframes.is_empty()
                && stackframes
                    .last_mut()
                    .unwrap()
                    .get_byte_reader(self)
                    .has_next()
            {
                let instr = Bytecode::try_from(
                    stackframes
                        .last_mut()
                        .unwrap()
                        .get_byte_reader(self)
                        .read_u8(),
                )
                .expect("GVM: [Bytecode] Unknown Bytecode instruction!");
                // println!("{}: {}", stackframes.len(), instr.to_string());
                //println!("Opstack.len = {}", operation_stack.len());
                // let start = Instant::now();

                match instr {
                Bytecode::Nop => {}
                Bytecode::Hint => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let hint = String::from_utf8(stackframe.get_byte_reader(self).read_buffer()).unwrap();
                    let hint_args: Vec<&str> = hint.split(";").collect();
                    if hint_args.len() < 1 {
                        continue;
                    }
                    /*
                     * *** hint debugging notation ***
                     * bp // set break point
                     * ln;100 // set line number
                     * fl;./src/helloWorld.gsm // set file path
                     * sy;name;i1;0 // set local symbol
                    */
                    match hint_args[0] {
                        "ln" => {
                            let line_num = hint_args.get(1)
                                .expect("GVM: [Hint] ln: Line hint requires a line number at argument pos 1!")
                                .parse::<u32>()
                                .expect("GVM: [Hint] ln: Line hint requires an u32 as line number at argument pos 1!");
                            
                            stackframe.debugger.set_line(line_num, self);
                            // stackframe.debugger.debugging(self);
                        },
                        "fl" => {
                            let file_path = hint_args.get(1)
                                .expect("GVM: [Hint] fl: File hint requires a file path at argument pos 1!")
                                .to_string();
                            stackframe.debugger.set_file(file_path, self);
                        },
                        "sy" => {
                            stackframe.debugger.add_symbol(DebugSymbol {
                                name: hint_args.get(1)
                                    .expect("GVM: [Hint] lc: Local Symbol requires a name at argument pos 1!")
                                    .to_string(),
                                type_id: GismoSymbolType::from(
                                    hint_args.get(2)
                                    .expect("GVM: [Hint] lc: Local Symbol requires a type at argument pos 2!")
                                ),
                                scope: GismoSymbolScope::Local,
                                index: hint_args.get(2)
                                    .expect("GVM: [Hint] lc: Local Symbol requires an index at argument pos 3!")
                                    .parse::<u32>()
                                    .expect("GVM: [Hint] lc: Local Symbol requires an u32 number as index at argument pos 3!")
                            });
                        }
                        _ => {}
                    }
                }
                Bytecode::LoadConstNum8 => {
                    operation_stack.push(StackElement::Num(
                        self.const_num8[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadConstNum16 => {
                    operation_stack.push(StackElement::Num(
                        self.const_num16[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadConstNum32 => {
                    operation_stack.push(StackElement::Num(
                        self.const_num32[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadConstNum64 => {
                    operation_stack.push(StackElement::Num(
                        self.const_num64[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadGlobalNum8 => {
                    operation_stack.push(StackElement::Num(
                        self.global_num8[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadGlobalNum16 => {
                    operation_stack.push(StackElement::Num(
                        self.global_num16[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadGlobalNum32 => {
                    operation_stack.push(StackElement::Num(
                        self.global_num32[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::LoadGlobalNum64 => {
                    operation_stack.push(StackElement::Num(
                        self.global_num64[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize] as u64,
                    ));
                }
                Bytecode::StoreGlobalNum8 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let pos = stackframes.last_mut().unwrap().get_byte_reader(self).read_u32();
                            self.global_num8[pos as usize] = x as u8
                        }
                        _ => panic!("GVM: [StoreGlobalNum8] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreGlobalNum8] Operation stack is empty!"),
                },
                Bytecode::StoreGlobalNum16 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let pos = stackframes.last_mut().unwrap().get_byte_reader(self).read_u32();
                            self.global_num16[pos as usize] = x as u16
                        }
                        _ => panic!("GVM: [StoreGlobalNum16] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreGlobalNum16] Operation stack is empty!"),
                },
                Bytecode::StoreGlobalNum32 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let pos = stackframes.last_mut().unwrap().get_byte_reader(self).read_u32();
                            self.global_num32[pos as usize] = x as u32
                        }
                        _ => panic!("GVM: [StoreGlobalNum32] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreGlobalNum32] Operation stack is empty!"),
                },
                Bytecode::StoreGlobalNum64 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let pos = stackframes.last_mut().unwrap().get_byte_reader(self).read_u32();
                            self.global_num64[pos as usize] = x as u64
                        }
                        _ => panic!("GVM: [StoreGlobalNum64] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreGlobalNum64] Operation stack is empty!"),
                },
                Bytecode::LoadLocalNum8 => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Num(
                        stackframe.local_register.local_num8[pos as usize] as u64,
                    ));
                }
                Bytecode::LoadLocalNum16 => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Num(
                        stackframe.local_register.local_num16[pos as usize] as u64,
                    ));
                }
                Bytecode::LoadLocalNum32 => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Num(
                        stackframe.local_register.local_num32[pos as usize] as u64,
                    ));
                }
                Bytecode::LoadLocalNum64 => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Num(
                        stackframe.local_register.local_num64[pos as usize] as u64,
                    ));
                }
                Bytecode::StoreLocalNum8 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_num8[pos as usize] = x as u8
                        }
                        _ => panic!("GVM: [StoreLocalNum8] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreLocalNum8] Operation stack is empty!"),
                },
                Bytecode::StoreLocalNum16 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_num16[pos as usize] = x as u16
                        }
                        _ => panic!("GVM: [StoreLocalNum16] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreLocalNum16] Operation stack is empty!"),
                },
                Bytecode::StoreLocalNum32 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_num32[pos as usize] = x as u32
                        }
                        _ => panic!("GVM: [StoreLocalNum32] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreLocalNum32] Operation stack is empty!"),
                },
                Bytecode::StoreLocalNum64 => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_num64[pos as usize] = x as u64
                        }
                        _ => panic!("GVM: [StoreLocalNum64] Requires an number to store!"),
                    },
                    None => panic!("GVM: [StoreLocalNum64] Operation stack is empty!"),
                },

                Bytecode::AddI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                zip_zack_encode(
                                    zip_zack_decode(i64::from_be_bytes(a.to_be_bytes()))
                                    + zip_zack_decode(i64::from_be_bytes(b.to_be_bytes()))
                                )
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [AddI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [AddI] Operation stack is empty!"),
                },

                Bytecode::AddU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(a + b))
                        }
                        _ => panic!("GVM: [AddU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [AddU] Operation stack is empty!"),
                },

                Bytecode::AddF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                (f64::from_be_bytes(a.to_be_bytes())
                                    + f64::from_be_bytes(b.to_be_bytes()))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [AddF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [AddF] Operation stack is empty!"),
                },
                Bytecode::SubI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                zip_zack_encode(zip_zack_decode(i64::from_be_bytes(a.to_be_bytes()))
                                    - zip_zack_decode(i64::from_be_bytes(b.to_be_bytes())))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [SubI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [SubI] Operation stack is empty!"),
                },
                Bytecode::SubU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(a - b))
                        }
                        _ => panic!("GVM: [SubU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [SubU] Operation stack is empty!"),
                },
                Bytecode::SubF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                (f64::from_be_bytes(a.to_be_bytes())
                                    - f64::from_be_bytes(b.to_be_bytes()))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [SubF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [SubF] Operation stack is empty!"),
                },
                Bytecode::MulI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                zip_zack_encode(zip_zack_decode(i64::from_be_bytes(a.to_be_bytes()))
                                    * zip_zack_decode(i64::from_be_bytes(b.to_be_bytes())))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [MulI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [MulI] Operation stack is empty!"),
                },
                Bytecode::MulU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(a * b))
                        }
                        _ => panic!("GVM: [MulU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [MulU] Operation stack is empty!"),
                },
                Bytecode::MulF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                (f64::from_be_bytes(a.to_be_bytes())
                                    * f64::from_be_bytes(b.to_be_bytes()))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [MulF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [MulF] Operation stack is empty!"),
                },
                Bytecode::DivI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                zip_zack_encode(zip_zack_decode(i64::from_be_bytes(a.to_be_bytes()))
                                    / zip_zack_decode(i64::from_be_bytes(b.to_be_bytes())))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [DivI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [DivI] Operation stack is empty!"),
                },
                Bytecode::DivU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(a / b))
                        }
                        _ => panic!("GVM: [DivU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [DivU] Operation stack is empty!"),
                },
                Bytecode::DivF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                (f64::from_be_bytes(a.to_be_bytes())
                                    / f64::from_be_bytes(b.to_be_bytes()))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [DivF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [DivF] Operation stack is empty!"),
                },
                Bytecode::And => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack
                            .push(StackElement::Num(a & b)),
                        _ => panic!("GVM: [And] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [And] Operation stack is empty!"),
                },
                Bytecode::Or => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack
                            .push(StackElement::Num(a | b)),
                        _ => panic!("GVM: [Or] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [Or] Operation stack is empty!"),
                },
                Bytecode::Not => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(x) => {
                            operation_stack.push(StackElement::Num(if x > 0 { 0 } else { 1 }))
                        }
                        _ => panic!("GVM: [Not] Requires a number to operate with!"),
                    },
                    None => panic!("GVM: [Not] Operation stack is empty!"),
                },
                Bytecode::EqI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(if a == b { 1 } else { 0 }))
                        }
                        _ => panic!("GVM: [EqI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqI] Operation stack is empty!"),
                },
                Bytecode::EqU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(if a == b { 1 } else { 0 }))
                        }
                        _ => panic!("GVM: [EqU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqU] Operation stack is empty!"),
                },
                Bytecode::EqF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(if a == b { 1 } else { 0 }))
                        }
                        _ => panic!("GVM: [EqF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqF] Operation stack is empty!"),
                },
                Bytecode::EqIU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if zip_zack_decode(
                                i64::from_be_bytes(a.to_be_bytes())
                            ) == b as i64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [EqIU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqIU] Operation stack is empty!"),
                },
                Bytecode::EqFI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if f64::from_be_bytes(a.to_be_bytes())
                                    == zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    ) as f64
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [EqFI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqFI] Operation stack is empty!"),
                },
                Bytecode::EqFU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if f64::from_be_bytes(a.to_be_bytes()) == b as f64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [EqFU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [EqFU] Operation stack is empty!"),
                },
                Bytecode::GreaterI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if zip_zack_decode(
                                    i64::from_be_bytes(a.to_be_bytes())
                                )
                                    > zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    )
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterI] Operation stack is empty!"),
                },
                Bytecode::GreaterU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(if a > b { 1 } else { 0 }))
                        }
                        _ => panic!("GVM: [GreaterU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterU] Operation stack is empty!"),
                },
                Bytecode::GreaterF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if f64::from_be_bytes(a.to_be_bytes())
                                    > f64::from_be_bytes(b.to_be_bytes())
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterF] Operation stack is empty!"),
                },
                Bytecode::GreaterIU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if zip_zack_decode(
                                i64::from_be_bytes(a.to_be_bytes())
                            ) > b as i64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [GreaterIU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterIU] Operation stack is empty!"),
                },
                Bytecode::GreaterFI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if f64::from_be_bytes(a.to_be_bytes())
                                    > zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    ) as f64
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterFI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterFI] Operation stack is empty!"),
                },
                Bytecode::GreaterFU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if f64::from_be_bytes(a.to_be_bytes()) > b as f64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [GreaterFU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterFU] Operation stack is empty!"),
                },
                Bytecode::LessI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if zip_zack_decode(
                                    i64::from_be_bytes(a.to_be_bytes())
                                )
                                    < zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    )
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterI] Operation stack is empty!"),
                },
                Bytecode::LessU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(if a < b { 1 } else { 0 }))
                        }
                        _ => panic!("GVM: [GreaterU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterU] Operation stack is empty!"),
                },
                Bytecode::LessF => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if f64::from_be_bytes(a.to_be_bytes())
                                    < f64::from_be_bytes(b.to_be_bytes())
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterF] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterF] Operation stack is empty!"),
                },
                Bytecode::LessIU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if zip_zack_decode(
                                i64::from_be_bytes(a.to_be_bytes())
                            ) < b as i64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [GreaterIU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterIU] Operation stack is empty!"),
                },
                Bytecode::LessFI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                if f64::from_be_bytes(a.to_be_bytes())
                                    < zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    ) as f64
                                {
                                    1
                                } else {
                                    0
                                },
                            ))
                        }
                        _ => panic!("GVM: [GreaterFI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterFI] Operation stack is empty!"),
                },
                Bytecode::LessFU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => operation_stack.push(
                            StackElement::Num(if f64::from_be_bytes(a.to_be_bytes()) < b as f64 {
                                1
                            } else {
                                0
                            }),
                        ),
                        _ => panic!("GVM: [GreaterFU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [GreaterFU] Operation stack is empty!"),
                },
                Bytecode::LoadGlobalCmplx => {
                    self.global_cmplxs.push(Vec::new());
                    operation_stack.push(StackElement::Cmplx(
                        self.global_cmplxs
                            .swap_remove(stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize),
                    ));
                }
                Bytecode::LoadLocalCmplx => {
                    let stackframe = stackframes.last_mut().unwrap();
                    stackframe.local_register.local_cmplxs.push(Vec::new());
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Cmplx(
                        stackframe.local_register.local_cmplxs
                            .swap_remove(pos as usize),
                    ));
                },
                Bytecode::StoreGlobalCmplx => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Cmplx(cmplx) => {
                            self.global_cmplxs.push(cmplx);
                            self.global_cmplxs.swap_remove(stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize);
                        },
                        _ => panic!("GVM: [StoreGlobalCmplx] Top value on the stack must be a complex!")
                    },
                    None => panic!("GVM: [StoreGlobalCmplx] Operation stack is empty!"),
                },
                Bytecode::StoreLocalCmplx => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Cmplx(cmplx) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_cmplxs.push(cmplx);
                            stackframe.local_register.local_cmplxs.swap_remove(pos as usize);
                        },
                        _ => panic!("GVM: [StoreLocalCmplx] Top value on the stack must be a complex!")
                    },
                    None => panic!("GVM: [StoreLocalCmplx] Operation stack is empty!"),
                },
                Bytecode::CmplxAddElement => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(element), Some(cmplx_element)) => match cmplx_element {
                        StackElement::Cmplx(mut cmplx) => {
                            cmplx.push(element);
                            operation_stack.push(StackElement::Cmplx(cmplx));
                        },
                        _ => panic!("GVM: [CmplxAddElement] Top value on the stack must be a complex!")
                    },
                    _ => panic!("GVM: [CmplxAddElement] Operation stack is empty!"),
                },
                Bytecode::CmplxRemoveElement => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(index_element), Some(cmplx_element)) => match (cmplx_element, index_element) {
                        (StackElement::Cmplx(mut cmplx), StackElement::Num(index)) => {
                            operation_stack.push(cmplx.remove(index as usize));
                            operation_stack.push(StackElement::Cmplx(cmplx));
                        },
                        _ => panic!("GVM: [CmplxRemoveElement] Requires cmplx on top and then index as number!")
                    },
                    _ => panic!("GVM: [CmplxRemoveElement] Operation stack is empty!"),
                },
                Bytecode::CmplxSize => match operation_stack.pop() {
                    Some(cmplx_element) => match cmplx_element {
                        StackElement::Cmplx(cmplx)=> {
                            operation_stack.push(StackElement::Num(cmplx.len() as u64));
                            operation_stack.push(StackElement::Cmplx(cmplx));
                        },
                        _ => panic!("GVM: [CmplxSize] Top value on the stack must be a complex!")
                    },
                    _ => panic!("GVM: [CmplxSize] Operation stack is empty!"),
                },
                Bytecode::CmplxLoadElement => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(index_element), Some(cmplx_element)) => match (cmplx_element, index_element) {
                        (StackElement::Cmplx(mut cmplx), StackElement::Num(index)) => {
                            let element = match cmplx[index as usize] {
                                StackElement::Cmplx(_) => {
                                    cmplx.push(StackElement::Cmplx(Vec::new()));
                                    cmplx.swap_remove(index as usize)
                                },
                                _ => cmplx[index as usize].clone()
                            };
                            operation_stack.push(element);
                            operation_stack.push(StackElement::Cmplx(cmplx));
                        },
                        _ => panic!("GVM: [CmplxLoadElement] Requires cmplx on top and then index as number!")
                    }
                    _ => panic!("GVM: [CmplxLoadElement] Operation stack is empty!"),
                },
                Bytecode::CmplxStoreElement => match (operation_stack.pop(), operation_stack.pop(), operation_stack.pop()) {
                    (Some(index_element), Some(store_element), Some(cmplx_element)) => match (cmplx_element, index_element, store_element) {
                        (StackElement::Cmplx(mut cmplx), StackElement::Num(index), element) => {
                            cmplx[index as usize] = element;
                            operation_stack.push(StackElement::Cmplx(cmplx));
                        },
                        _ => panic!("GVM: [CmplxStoreElement] Requires cmplx on top, then index as number and then a element to store!")
                    },
                    _ => panic!("GVM: [CmplxStoreElement] Operation stack is empty!"),
                },
                Bytecode::LoadConstFunc => {
                    operation_stack.push(StackElement::Func(self.const_functions[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize].const_position));
                },
                Bytecode::LoadGlobalFunc => {
                    operation_stack.push(StackElement::Func(self.global_functions[stackframes.last_mut().unwrap().get_byte_reader(self).read_u32() as usize]));
                },
                Bytecode::LoadLocalFunc => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(StackElement::Func(stackframe.local_register.local_functions[pos as usize]));
                },
                Bytecode::StoreGlobalFunc => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Func(func) => {
                            let pos = stackframes.last_mut().unwrap().get_byte_reader(self).read_u32();
                            self.global_functions[pos as usize] = func
                        },
                        _ => panic!("GVM: [StoreGlobalFunc] Requires a function to store!"),
                    },
                    None => panic!("GVM: [StoreGlobalFunc] Operation stack is empty!"),
                },
                Bytecode::StoreLocalFunc => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Func(func) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_functions[pos as usize] = func
                        },
                        _ => panic!("GVM: [StoreLocalFunc] Requires a function to store!"),
                    },
                    None => panic!("GVM: [StoreLocalFunc] Operation stack is empty!"),
                },
                Bytecode::CallFunc => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Func(func) => {
                            
                            // Check for the arguments on the stack
                            let argument_count = stackframes.last_mut().unwrap()
                                .get_byte_reader(self).read_u32();
                            
                            // putting the function to execute onto the stack
                            let mut stackframe = GismoStackFrame::from(&self.const_functions[func as usize], operation_stack.len());
                            stackframe.argument_count = argument_count;
                            stackframes.push(stackframe);

                            // Now the next instruction that will be executed
                            // will be from the called function
                        }
                        _ => panic!("GVM: [CallFunc] Requires a function on top to call!"),
                    }
                    None => panic!("GVM: [CallFunc] Operation stack is empty!"),
                },
                Bytecode::ReturnElement => match operation_stack.pop() {
                    Some(return_element) => {
                        let stackframe = stackframes.last_mut().unwrap();
                        while operation_stack.len() > (stackframe.stack_offset - stackframe.argument_count as usize) {
                            operation_stack.pop().expect("GVM: [CallFunc] Operation stack is empty!");
                        }
                        operation_stack.push(return_element);

                        stackframes.pop();
                    },
                    None => panic!("GVM: [ReturnElement] Operation stack is empty!")
                },
                Bytecode::Pop => match operation_stack.pop() {
                    None => panic!("GVM: [Pop] Operation stack is empty!"),
                    Some(_) => {}
                },
                Bytecode::Swap => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(top1), Some(top2)) => {
                        operation_stack.push(top1);
                        operation_stack.push(top2);
                    },
                    _ => panic!("GVM: [Swap] Operation stack is empty!")
                },
                Bytecode::Rot => match (operation_stack.pop(), operation_stack.pop(), operation_stack.pop()) {
                    (Some(top1), Some(top2), Some(top3)) => {
                        operation_stack.push(top1);
                        operation_stack.push(top3);
                        operation_stack.push(top2);
                    },
                    _ => panic!("GVM: [Rot] Operation stack is empty!")
                },
                Bytecode::Exit => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(exit_code) => process::exit(exit_code as i32),
                        _ => panic!("GVM: [Exit] Requires number for exit code!")
                    }
                    None => panic!("GVM: [Exit] Operation stack is empty!")
                },
                Bytecode::LoadConstText => {
                    let stackframe = stackframes.last_mut().unwrap();
                    operation_stack.push(StackElement::Text(GismoText::from(stackframe.get_byte_reader(self).read_u32())));
                },
                Bytecode::LoadGlobalText => {
                    let stackframe = stackframes.last_mut().unwrap();
                    operation_stack.push(
                        StackElement::Text(
                            self.global_texts.get(stackframe.get_byte_reader(self).read_u32() as usize).unwrap().clone()
                        )
                    );
                },
                Bytecode::LoadLocalText => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    operation_stack.push(
                        StackElement::Text(
                            stackframe.local_register.local_texts.get(
                                pos as usize
                            ).unwrap().clone()
                        )
                    );
                },
                Bytecode::StoreGlobalText => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(value) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            self.global_texts[pos as usize] = value;
                        }
                        _ => panic!("GVM: [StoreGlobalText] Requires text to store!")
                    },
                    None => panic!("GVM: [StoreGlobalText] Operation stack is empty!")
                },
                Bytecode::StoreLocalText => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(value) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            stackframe.local_register.local_texts[pos as usize] = value;
                        }
                        _ => panic!("GVM: [StoreLocalText] Requires text to store!")
                    },
                    None => panic!("GVM: [StoreLocalText] Operation stack is empty!")
                },
                Bytecode::TextAddChar => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(element_character), Some(element_text)) => match (element_text, element_character) {
                        (StackElement::Text(mut text), StackElement::Num(character)) => {
                            text.add_char(character, self);
                            operation_stack.push(StackElement::Text(text));
                        },
                        _ => panic!("GVM: [TextAddChar] Requires character as number at top of stack, then text!")
                    },
                    _ => panic!("GVM: [TextAddChar] Operation stack is empty!")
                },
                Bytecode::TextRemoveChar => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(element_index), Some(element_text)) => match (element_text, element_index) {
                        (StackElement::Text(mut text), StackElement::Num(index)) => {
                            text.remove_char(index, self);
                            operation_stack.push(StackElement::Text(text));
                        },
                        _ => panic!("GVM: [TextRemoveChar] Requires index as number at top of stack, then text!")
                    },
                    _ => panic!("GVM: [TextRemoveChar] Operation stack is empty!")
                },
                Bytecode::TextPopChar => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(mut text) => {
                            text.pop_char(self);
                            operation_stack.push(StackElement::Text(text));
                        }
                        _ => panic!("GVM: [TextPopChar] Requires text to pop character!")
                    },
                    None => panic!("GVM: [TextPopChar] Operation stack is empty!")
                },
                Bytecode::TextGetSize => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            operation_stack.push(StackElement::Num(text.get_size(self) as u64));
                        }
                        _ => panic!("GVM: [TextGetSize] Requires text!")
                    }
                    None => panic!("GVM: [TextGetSize] Operation stack is empty!")
                },
                Bytecode::TextGetChar => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(element_index), Some(element_text)) => match (element_text, element_index) {
                        (StackElement::Text(text), StackElement::Num(index)) => {
                            operation_stack.push(StackElement::Num(text.get_char(index, self)));
                        }
                        _ => panic!("GVM: [TextGetChar] Requires index as number and text!")
                    }
                    _ => panic!("GVM: [TextGetChar] Operation stack is empty!")
                },
                Bytecode::CmplxClone => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Cmplx(cmplx) => {
                            let cmplx_clone = cmplx.clone();
                            operation_stack.push(StackElement::Cmplx(cmplx));
                            operation_stack.push(StackElement::Cmplx(cmplx_clone));
                        }
                        _ => panic!("GVM: [CmplxClone] Requires complex to clone!")
                    },
                    None => panic!("GVM: [CmplxClone] Operation stack is empty!")
                },
                Bytecode::TextClone => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            let text_clone = text.clone();
                            operation_stack.push(StackElement::Text(text));
                            operation_stack.push(StackElement::Text(text_clone));
                        },
                        _ => panic!("GVM: [TextClone] Requires text to clone!")
                    }
                    None => panic!("GVM: [TextClone] Operation stack is empty!")
                },
                Bytecode::PrintI => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let integer_num = zip_zack_decode(i64::from_be_bytes(num.to_be_bytes()));
                            print!("{}", integer_num);
                        },
                        _ => panic!("GVM: [PrintI] Requires number to print!")
                    }
                    None => panic!("GVM: [PrintI] Operation stack is empty!")
                },
                Bytecode::PrintU => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(unsigned_num) => {
                            print!("{}", unsigned_num);
                        },
                        _ => panic!("GVM: [PrintU] Requires number to print!")
                    }
                    None => panic!("GVM: [PrintU] Operation stack is empty!")
                },
                Bytecode::PrintF => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let float_num = f64::from_be_bytes(num.to_be_bytes());
                            print!("{}", float_num);
                        },
                        _ => panic!("GVM: [PrintF] Requires number to print!")
                    }
                    None => panic!("GVM: [PrintF] Operation stack is empty!")
                },
                Bytecode::PrintC => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(character) => {
                            print!("{}", character as u8 as char);
                        },
                        _ => panic!("GVM: [PrintC] Requires number to print!")
                    }
                    None => panic!("GVM: [PrintC] Operation stack is empty!")
                },
                Bytecode::PrintText => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            print!("{}", text.to_text(self));
                        },
                        _ => panic!("GVM: [PrintText] Requires text to print!")
                    }
                    None => panic!("GVM: [PrintText] Operation stack is empty!")
                },
                Bytecode::Newline => {
                    print!("\n");
                },

                Bytecode::Cmplx2Text => todo!(),
                Bytecode::GetInstance => todo!(),

                Bytecode::JumpAbs => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u32();
                    stackframe.get_byte_reader(self).jump_abs(pos);
                },
                Bytecode::JumpNeg => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u16() + 3;
                    stackframe.get_byte_reader(self).jump_neg(pos);
                },
                Bytecode::JumpPos => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let pos = stackframe.get_byte_reader(self).read_u16();
                    stackframe.get_byte_reader(self).jump_pos(pos);
                },
                Bytecode::JumpAbsIfTrue => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            if cond > 0 {
                                stackframe.get_byte_reader(self).jump_abs(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpAbsIfTrue] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpAbsIfTrue] Operation stack is empty!")
                },
                Bytecode::JumpAbsIfFalse => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u32();
                            if cond < 1 {
                                stackframe.get_byte_reader(self).jump_abs(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpAbsIfFalse] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpAbsIfFalse] Operation stack is empty!")
                },
                Bytecode::JumpNegIfTrue => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u16() + 3;
                            if cond > 0 {
                                stackframe.get_byte_reader(self).jump_neg(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpNegIfTrue] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpNegIfTrue] Operation stack is empty!")
                },
                Bytecode::JumpNegIfFalse => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u16() + 3;
                            if cond < 1 {
                                stackframe.get_byte_reader(self).jump_neg(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpNegIfFalse] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpNegIfFalse] Operation stack is empty!")
                },
                Bytecode::JumpPosIfTrue => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u16();
                            if cond > 0 {
                                stackframe.get_byte_reader(self).jump_pos(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpPosIfTrue] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpPosIfTrue] Operation stack is empty!")
                },
                Bytecode::JumpPosIfFalse => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(cond) => {
                            let stackframe = stackframes.last_mut().unwrap();
                            let pos = stackframe.get_byte_reader(self).read_u16();
                            if cond < 1 {
                                stackframe.get_byte_reader(self).jump_pos(pos);
                            }
                        },
                        _ => panic!("GVM: [JumpPosIfFalse] Requires an number as condition!")
                    },
                    None => panic!("GVM: [JumpPosIfFalse] Operation stack is empty!")
                },
                Bytecode::ModI => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(u64::from_be_bytes(
                                zip_zack_encode(zip_zack_decode(
                                    i64::from_be_bytes(a.to_be_bytes())
                                )
                                    % zip_zack_decode(
                                        i64::from_be_bytes(b.to_be_bytes())
                                    ))
                                .to_be_bytes(),
                            )))
                        }
                        _ => panic!("GVM: [ModI] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [ModI] Operation stack is empty!"),
                },
                Bytecode::ModU => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(a % b))
                        }
                        _ => panic!("GVM: [ModU] Requires two numbers to operate with!"),
                    },
                    _ => panic!("GVM: [ModU] Operation stack is empty!"),
                },
                Bytecode::CmplxBuildEmpty => {
                    operation_stack.push(StackElement::Cmplx(
                        Vec::new()
                    ));
                },
                Bytecode::CmplxBuildNew => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let size = stackframe.get_byte_reader(self).read_u32();
                    let mut cmplx: Vec<StackElement> = Vec::new(); 
                    for _ in 0..size {
                        cmplx.push(operation_stack.pop()
                            .expect("GVM: [CmplxBuildNew] Operation stack is empty!"));
                    }

                    operation_stack.push(StackElement::Cmplx(cmplx));
                },
                Bytecode::InputI => {
                    let mut input_line = String::new();
                    io::stdout().flush().unwrap();
                    io::stdin()
                        .read_line(&mut input_line)
                        .expect("GVM: [InputI] IO Error!");
                    let input_number: i64 = zip_zack_encode(
                        input_line.trim().parse().expect("GVM: [InputI] Failed parsing integer!")
                    );

                    operation_stack.push(
                        StackElement::Num(
                            u64::from_be_bytes(input_number.to_be_bytes())
                        )
                    );
                },
                Bytecode::InputU => {
                    let mut input_line = String::new();
                    io::stdout().flush().unwrap();
                    io::stdin()
                        .read_line(&mut input_line)
                        .expect("GVM: [InputU] IO Error!");
                    let input_number: u64 = input_line.trim().parse().expect("GVM: [InputU] Failed parsing unsigned integer!");

                    operation_stack.push(
                        StackElement::Num(
                            input_number
                        )
                    );
                },
                Bytecode::InputF => {
                    let mut input_line = String::new();
                    io::stdout().flush().unwrap();
                    io::stdin()
                        .read_line(&mut input_line)
                        .expect("GVM: [InputF] IO Error!");

                    let input_number: f64 = input_line.trim().parse().expect("GVM: [InputF] Failed parsing floating point number!");

                    operation_stack.push(
                        StackElement::Num(
                            u64::from_be_bytes(input_number.to_be_bytes())
                        )
                    );
                },
                Bytecode::InputText => {
                    let mut input_line = String::new();
                    io::stdout().flush().unwrap();
                    io::stdin()
                        .read_line(&mut input_line)
                        .expect("GVM: [InputText] IO Error!");

                    // Removing newline at the end
                    if input_line.ends_with('\n') || input_line.ends_with('\r') {
                        input_line.pop();
                        if input_line.ends_with('\r') {
                            input_line.pop();
                        }
                    }

                    operation_stack.push(
                        StackElement::Text(
                            GismoText::new(input_line)
                        )
                    );
                },
                Bytecode::InputLine => {
                    let mut input_line = String::new();
                    io::stdout().flush().unwrap();
                    io::stdin()
                        .read_line(&mut input_line)
                        .expect("GVM: [InputLine] IO Error!");

                    // Removing newline at the end
                    if input_line.ends_with('\n') || input_line.ends_with('\r') {
                        input_line.pop();
                        if input_line.ends_with('\r') {
                            input_line.pop();
                        }
                    }

                    operation_stack.push(
                        StackElement::Text(
                            GismoText::new(input_line)
                        )
                    );
                },
                Bytecode::TextSetChar => match (operation_stack.pop(), operation_stack.pop(), operation_stack.pop()) {
                    (Some(element_character), Some(element_index), Some(element_text)) => match (element_text, element_index, element_character) {
                        (StackElement::Text(mut text), StackElement::Num(index), StackElement::Num(character)) => {
                            text.set_char(index, character, self);
                            operation_stack.push(StackElement::Text(text));
                        },
                        _ => panic!("GVM: [TextAddChar] Requires character as number at top of stack, then text!")
                    },
                    _ => panic!("GVM: [TextAddChar] Operation stack is empty!")
                },
                Bytecode::LoadArgument => {
                    let stackframe = stackframes.last_mut().unwrap();
                    let argument_pos = (stackframe.stack_offset - stackframe.get_byte_reader(self).read_u32() as usize) - 1;
                    let argument = operation_stack.get(argument_pos)
                        .expect("GVM: [LoadArgument] Operation stack is empty at argument position!");
                    if let StackElement::Cmplx(_) = argument {
                        operation_stack.push(StackElement::Cmplx(Vec::new()));
                        let cmplx = operation_stack.swap_remove(argument_pos);
                        operation_stack.push(cmplx);
                    } else {
                        operation_stack.push(argument.clone());
                    }
                },
                Bytecode::I2U => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    zip_zack_decode(i64::from_be_bytes(num.to_be_bytes())) as u64
                                )
                            );
                        }
                        _ => panic!("GVM: [I2U] Requires number to convert!")
                    },
                    None => panic!("GVM: [I2U] Operation stack is empty!")
                },
                Bytecode::I2F => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes((zip_zack_decode(i64::from_be_bytes(num.to_be_bytes())) as f64).to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [I2F] Requires number to convert!")
                    },
                    None => panic!("GVM: [I2F] Operation stack is empty!")
                },
                Bytecode::U2I => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes(zip_zack_encode(num as i64).to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [U2I] Requires number to convert!")
                    },
                    None => panic!("GVM: [U2I] Operation stack is empty!")
                },
                Bytecode::U2F => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes((num as f64).to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [U2F] Requires number to convert!")
                    },
                    None => panic!("GVM: [U2F] Operation stack is empty!")
                },
                Bytecode::F2I => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes(zip_zack_encode(f64::from_be_bytes(num.to_be_bytes()) as i64).to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [F2I] Requires number to convert!")
                    },
                    None => panic!("GVM: [F2I] Operation stack is empty!")
                },
                Bytecode::F2U => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes((f64::from_be_bytes(num.to_be_bytes()) as u64).to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [F2U] Requires number to convert!")
                    },
                    None => panic!("GVM: [F2U] Operation stack is empty!")
                },
                Bytecode::IsNum => {
                    let result = match operation_stack.pop() {
                        Some(element) => match element {
                            StackElement::Num(_) => StackElement::Num(1),
                            _ => StackElement::Num(0)
                        },
                        _ => panic!("GVM: [IsNum] Operation stack is empty!")
                    };
                    operation_stack.push(result);
                },
                Bytecode::IsText => {
                    let result = match operation_stack.pop() {
                        Some(element) => match element {
                            StackElement::Text(_) => StackElement::Num(1),
                            _ => StackElement::Num(0)
                        },
                        _ => panic!("GVM: [IsText] Operation stack is empty!")
                    };
                    operation_stack.push(result);
                },
                Bytecode::IsCmplx => {
                    let result = match operation_stack.pop() {
                        Some(element) => match element {
                            StackElement::Cmplx(_) => StackElement::Num(1),
                            _ => StackElement::Num(0)
                        },
                        _ => panic!("GVM: [IsCmplx] Operation stack is empty!")
                    };
                    operation_stack.push(result);
                },
                Bytecode::IsFunc => {
                    let result = match operation_stack.pop() {
                        Some(element) => match element {
                            StackElement::Func(_) => StackElement::Num(1),
                            _ => StackElement::Num(0)
                        },
                        _ => panic!("GVM: [IsFunc] Operation stack is empty!")
                    };
                    operation_stack.push(result);
                },
                Bytecode::IsNothing => {
                    let result = match operation_stack.pop() {
                        Some(element) => match element {
                            StackElement::Nothing=> StackElement::Num(1),
                            _ => StackElement::Num(0)
                        },
                        _ => panic!("GVM: [IsNothing] Operation stack is empty!")
                    };
                    operation_stack.push(result);
                },
                Bytecode::Float2Double => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let float = f32::from_ne_bytes((num as u32).to_be_bytes());
                            let double = float as f64;
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes(double.to_be_bytes())
                                )
                            );
                        }
                        _ => panic!("GVM: [Float2Double] Requires number to convert!")
                    }
                    None => panic!("GVM: [Float2Double] Operation stack is empty!")
                },
                Bytecode::Double2Float => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let float = f64::from_be_bytes(num.to_be_bytes()) as f32;
                            operation_stack.push(
                                StackElement::Num(
                                    u32::from_be_bytes(float.to_be_bytes()) as u64
                                )
                            );
                        }
                        _ => panic!("GVM: [Double2Float] Requires number to convert!")
                    }
                    None => panic!("GVM: [Double2Float] Operation stack is empty!")
                },
                Bytecode::BNot => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(StackElement::Num(
                                !num
                            ));
                        },
                        _ => panic!("GVM: [BNot] Requires number to negate bitwise!")
                    }
                    None => panic!("GVM: [BNot] Operation stack is empty!")
                },
                Bytecode::CmplxInit => match operation_stack.pop() {
                    Some(element) => {
                        let stackframe = stackframes.last_mut().unwrap();
                        operation_stack.push(
                            StackElement::Cmplx(
                                vec![element; stackframe.get_byte_reader(self).read_u32() as usize]
                            )
                        )
                    }
                    None => panic!("GVM: [CmplxInit] Operation stack is empty!")
                },
                Bytecode::I2Text => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let string = zip_zack_decode(i64::from_be_bytes(num.to_be_bytes())).to_string();
                            operation_stack.push(
                                StackElement::Text(
                                    GismoText::new(string)
                                )
                            );
                        },
                        _ => panic!("GVM: [I2Text] Requires number to be converted!")
                    }
                    None => panic!("GVM: [I2Text] Operation stack is empty!")
                },
                Bytecode::F2Text => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let string = f64::from_be_bytes(num.to_be_bytes()).to_string();
                            operation_stack.push(
                                StackElement::Text(
                                    GismoText::new(string)
                                )
                            );
                        },
                        _ => panic!("GVM: [F2Text] Requires number to be converted!")
                    }
                    None => panic!("GVM: [F2Text] Operation stack is empty!")
                },
                Bytecode::U2Text => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            let string = num.to_string();
                            operation_stack.push(
                                StackElement::Text(
                                    GismoText::new(string)
                                )
                            );
                        },
                        _ => panic!("GVM: [U2Text] Requires number to be converted!")
                    }
                    None => panic!("GVM: [U2Text] Operation stack is empty!")
                },
                Bytecode::Text2I => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            let num: i64 = zip_zack_encode(text.to_text(self).trim().parse().unwrap_or(0));
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes(num.to_be_bytes())
                                )
                            );
                        },
                        _ => panic!("GVM: [Text2I] Requires text to be converted!")
                    }
                    None => panic!("GVM: [Text2I] Operation stack is empty!")
                },
                Bytecode::Text2F => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            let num: f64 = text.to_text(self).trim().parse().unwrap_or(0.0);
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes(num.to_be_bytes())
                                )
                            );
                        },
                        _ => panic!("GVM: [Text2F] Requires text to be converted!")
                    }
                    None => panic!("GVM: [Text2F] Operation stack is empty!")
                },
                Bytecode::Text2U => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            let num: u64 = text.to_text(self).trim().parse().unwrap_or(0);
                            operation_stack.push(
                                StackElement::Num(
                                    num
                                )
                            );
                        },
                        _ => panic!("GVM: [Text2U] Requires text to be converted!")
                    }
                    None => panic!("GVM: [Text2U] Operation stack is empty!")
                },
                Bytecode::UnaryMinusI => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes((zip_zack_encode(-zip_zack_decode(i64::from_be_bytes(num.to_be_bytes())))).to_be_bytes())
                                )
                            );
                        },
                        _ => panic!("GVM: [UnaryMinusI] Requires number!")
                    }
                    None => panic!("GVM: [UnaryMinusI] Operation stack is empty!")
                },
                Bytecode::UnaryMinusF => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Num(num) => {
                            operation_stack.push(
                                StackElement::Num(
                                    u64::from_be_bytes((-f64::from_be_bytes(num.to_be_bytes())).to_be_bytes())
                                )
                            );
                        },
                        _ => panic!("GVM: [UnaryMinusF] Requires number!")
                    }
                    None => panic!("GVM: [UnaryMinusF] Operation stack is empty!")
                },
                Bytecode::TextConcat => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(element_b), Some(element_a)) => match (element_a, element_b) {
                        (StackElement::Text(mut a), StackElement::Text(b)) => {
                            
                            a.concat(&b, self);

                            operation_stack.push(
                                StackElement::Text(
                                    a
                                )
                            );
                        }
                        _ => panic!("GVM [TextConcat] Requires two texts to concat!")
                    },
                    _ => panic!("GVM: [TextConcat] Operation stack is empty!")
                },
                Bytecode::InputChar => todo!(),
                Bytecode::CallAsync => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Func(_func) => {
                            let mut arguments: Vec<StackElement> = vec![];

                            // Check for the arguments on the stack
                            let argument_count = stackframes.last_mut().unwrap()
                                .get_byte_reader(self).read_u32();
                            
                            for _ in 0..argument_count {
                                arguments.push(operation_stack.pop().expect(
                                    "GVM: [CallAsync] Operation stack is empty!"
                                ));
                            }
                            
                            // TODO: How the fuck?
                            // scope.spawn(|| {
                            //     // Execute function async in own stack
                            //     self.execute_func(func, arguments);
                            // });
                        }
                        _ => panic!("GVM: [CallAsync] Requires a function on top to call!"),
                    }
                    None => panic!("GVM: [CallAsync] Operation stack is empty!"),
                },
                Bytecode::Clock => todo!(),
                Bytecode::Time => todo!(),
                Bytecode::GllLoad => todo!(),
                Bytecode::GllSymbol => todo!(),
                Bytecode::GllExec => todo!(),
                Bytecode::GnlClose => todo!(),
                Bytecode::SetupIter => todo!(),
                Bytecode::NextIter => todo!(),
                Bytecode::TextHash => match operation_stack.pop() {
                    Some(element) => match element {
                        StackElement::Text(text) => {
                            operation_stack.push(StackElement::Num(
                                text.hash(self)
                            ));
                        }
                        _ => panic!("GVM: [TextHash] Requires text for hashing!")
                    }
                    None => panic!("GVM: [TextHash] Operation stack is empty!")
                },

                Bytecode::ShiftL => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                a << b
                            ));
                        }
                        _ => panic!("GVM: [ShiftL] Requires two numbers for shifting!")
                    }
                    _ => panic!("GVM: [ShiftL] Operation stack is empty!")
                },
                Bytecode::ShiftR => match (operation_stack.pop(), operation_stack.pop()) {
                    (Some(b), Some(a)) => match (a, b) {
                        (StackElement::Num(a), StackElement::Num(b)) => {
                            operation_stack.push(StackElement::Num(
                                a >> b
                            ));
                        }
                        _ => panic!("GVM: [ShiftR] Requires two numbers for shifting!")
                    }
                    _ => panic!("GVM: [ShiftR] Operation stack is empty!")
                },
            }

                // let duration = start.elapsed();

                // let instr_record = instr_monitoring.entry(instr.to_string()).or_insert(GismoRecord {
                //     name: instr.to_string(),
                //     count: 0,
                //     sum: 0,
                // });

                // instr_record.sum += duration.as_nanos();
                // instr_record.count += 1;

                if (!stackframes
                    .last_mut()
                    .unwrap()
                    .get_byte_reader(self)
                    .has_next())
                    && !stackframes.is_empty()
                {
                    let stackframe = stackframes.pop().unwrap();
                    while operation_stack.len()
                        > (stackframe.stack_offset - stackframe.argument_count as usize)
                    {
                        operation_stack.pop().unwrap();
                    }
                    operation_stack.push(StackElement::Nothing);
                }
            }

            // let mut records = Vec::from_iter(instr_monitoring.values());
            // records.sort_by(|a,b| a.average().cmp(&b.average()));

            // for record in records.iter() {
            //     println!("{} Average -> {} ({}/{})", record.name, record.average(), record.sum, record.count);
            // }
        });
    }
}
