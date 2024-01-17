CC=clang
TARGET=target
GIT_VERSION := "$(shell git describe --abbrev=4 --dirty --always --tags)"

gismo:
	mkdir -p $(TARGET)
	$(CC) -O2 -Wl,-stack_size -Wl,0x1000000 -o ./$(TARGET)/gismo ./compiler.c -DVERSION=\"$(GIT_VERSION)\"

debug:
	mkdir -p $(TARGET)
	$(CC) -g2 -Wl,-stack_size -Wl,0x1000000 -o ./$(TARGET)/gismo ./compiler.c -DVERSION=\"$(GIT_VERSION)\"
