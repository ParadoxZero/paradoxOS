
BIN := bin
BUILD := build

CC := i686-elf-gcc
AS := i686-elf-as

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra

mkdir -p $(BIN)
mkdir -p $(BUILD)

default: link

$(BUILD)/boot:
	$(AS) src/boot.s -o $(BUILD)/boot.o

$(BUILD)/kernel: build/boot
	$(CC) -c src/kernel.c -o $(BUILD)/kernel.o $(CFLAGS)

link: $(BUILD)/boot $(BUILD)/kernel
	$(CC) -T src/linker.ld -o $(BIN)/myos.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc
