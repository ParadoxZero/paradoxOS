
BIN := bin
BUILD := build

CC := i686-elf-gcc
AS := i686-elf-as

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra



default: all

all: clean iso

start: all
	qemu-system-i386 paradoxOS.iso

start_kernel: clean link
	qemu-system-i386 -kernel $(BIN)/paradoxOS.bin


$(BUILD)/boot.o:
	$(AS) src/boot.s -o $(BUILD)/boot.o

$(BUILD)/basic_vga.o:
	$(CC) -c src/basic_vga.c -o $(BUILD)/basic_vga.o $(CFLAGS)

$(BUILD)/kernel.o:
	$(CC) -c src/kernel.c  -o $(BUILD)/kernel.o $(CFLAGS)

link: $(BUILD)/boot.o $(BUILD)/kernel.o $(BUILD)/basic_vga.o
	$(CC) -T src/linker.ld -o $(BIN)/paradoxOS.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/basic_vga.o -lgcc

iso: link
	mkdir -p iso/boot/grub
	cp $(BIN)/paradoxOS.bin iso/boot/paradoxOS.bin
	cp config/grub/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue iso -o paradoxOS.iso

clean:
	$(shell rm -r $(BUILD))
	$(shell rm -r $(BIN))
	$(shell mkdir -p $(BIN))
	$(shell mkdir -p $(BUILD))