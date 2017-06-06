
BIN := bin
BUILD := build

CC := i686-elf-gcc
AS := i686-elf-as

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(shell mkdir -p $(BIN))
$(shell mkdir -p $(BUILD))

default: link

$(BUILD)/boot.o:
	$(AS) src/boot.s -o $(BUILD)/boot.o

$(BUILD)/basic_vga.o:
	$(CC) -c src/basic_vga.c -o $(BUILD)/basic_vga.o $(CFLAGS)

$(BUILD)/kernel.o: $(BUILD)/basic_vga.o
	$(CC) -c src/kernel.c $(BUILD)/basic_vga.o -o $(BUILD)/kernel.o $(CFLAGS)

link: $(BUILD)/boot.o $(BUILD)/kernel.o
	$(CC) -T src/linker.ld -o $(BIN)/myos.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc
