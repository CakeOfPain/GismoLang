#ifndef ByteWriter_h
#define ByteWriter_h

#define BYTEWRITER_GROWING_STEPS 300

typedef struct ByteWriter {
    char** str;
    unsigned int* length;
    unsigned int actualSize;
} ByteWriter;

ByteWriter ByteWriter_init(char** str, unsigned int* length) {
    ByteWriter byteWriter;
    byteWriter.str = str;
    byteWriter.length = length;
    byteWriter.actualSize = *length;
    return byteWriter;
}

void ByteWriter_writeByte(ByteWriter* byteWriter, unsigned char byte) {
    
    (*byteWriter->length)++;
    if (byteWriter->actualSize < *byteWriter->length) {
        byteWriter->actualSize += BYTEWRITER_GROWING_STEPS;
        (*byteWriter->str) = (char*) realloc((*byteWriter->str), sizeof(char) * (byteWriter->actualSize));
    }
    if(!(*byteWriter->str)) {
        puts("Out of Memory!");
        exit(1);
    }
    (*byteWriter->str)[*byteWriter->length - 1] = byte;
}

void ByteWriter_writeUShort(ByteWriter* byteWriter, unsigned short value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeShort(ByteWriter* byteWriter, short value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeUInt(ByteWriter* byteWriter, unsigned int value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeInt(ByteWriter* byteWriter, int value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeFloat(ByteWriter* byteWriter, float value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeULongLong(ByteWriter* byteWriter, unsigned long long value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[7]);
    ByteWriter_writeByte(byteWriter, buffer[6]);
    ByteWriter_writeByte(byteWriter, buffer[5]);
    ByteWriter_writeByte(byteWriter, buffer[4]);
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeLongLong(ByteWriter* byteWriter, long long value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[7]);
    ByteWriter_writeByte(byteWriter, buffer[6]);
    ByteWriter_writeByte(byteWriter, buffer[5]);
    ByteWriter_writeByte(byteWriter, buffer[4]);
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_writeDouble(ByteWriter* byteWriter, double value) {
    unsigned char* buffer = (unsigned char*) &value;
    ByteWriter_writeByte(byteWriter, buffer[7]);
    ByteWriter_writeByte(byteWriter, buffer[6]);
    ByteWriter_writeByte(byteWriter, buffer[5]);
    ByteWriter_writeByte(byteWriter, buffer[4]);
    ByteWriter_writeByte(byteWriter, buffer[3]);
    ByteWriter_writeByte(byteWriter, buffer[2]);
    ByteWriter_writeByte(byteWriter, buffer[1]);
    ByteWriter_writeByte(byteWriter, buffer[0]);
}

void ByteWriter_addOps(struct ByteWriter* byteWriter, char* ops, unsigned int length) {
    for(unsigned int i = 0; i < length; i++) {
        ByteWriter_writeByte(byteWriter, ops[i]);
    }
}

#endif