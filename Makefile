CC=clang
TARGET=target
GIT_VERSION := "$(shell git describe --abbrev=4 --dirty --always --tags)"

gismo:
	mkdir -p $(TARGET)
	$(CC) -o ./$(TARGET)/gismo ./compiler.c -DVERSION=\"$(GIT_VERSION)\"