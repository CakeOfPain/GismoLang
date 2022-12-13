pub struct ByteReader<'a> {
    buffer: &'a Vec<u8>,
    count: &'a mut usize,
}
impl<'a> ByteReader<'a> {
    pub fn new(buffer: &'a Vec<u8>, count: &'a mut usize) -> Self {
        Self { buffer, count }
    }

    pub fn has_next(&self) -> bool {
        *self.count < self.buffer.len()
    }

    pub fn read_u8(&mut self) -> u8 {
        if *self.count >= self.buffer.len() {
            panic!("GVM: [Bytecode Format] cannot parse bytecode!");
        }
        *self.count += 1;
        self.buffer[*self.count - 1]
    }

    pub fn read_u16(&mut self) -> u16 {
        u16::from_be_bytes([self.read_u8(), self.read_u8()])
    }

    pub fn read_u32(&mut self) -> u32 {
        u32::from_be_bytes([
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
        ])
    }

    pub fn read_u64(&mut self) -> u64 {
        u64::from_be_bytes([
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
            self.read_u8(),
        ])
    }

    pub fn read_buffer(&mut self) -> Vec<u8> {
        let mut buffer = Vec::new();
        let length = self.read_u32();
        for _ in 0..length {
            buffer.push(self.read_u8());
        }
        buffer
    }

    pub fn jump_abs(&mut self, pos: u32) {
        *self.count = pos as usize;
    }

    pub fn jump_pos(&mut self, pos: u16) {
        *self.count += pos as usize;
    }

    pub fn jump_neg(&mut self, pos: u16) {
        *self.count -= pos as usize;
    }
}
