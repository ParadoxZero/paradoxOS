
BIN := bin
BUILD := build
INCLUDEDIR := sysroot/usr/includes

CC := i686-elf-gcc --sysroot=sysroot -isystem=/usr/include
AS := i686-elf-as

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra



.PHONY: clean

default: all

all: clean set-up iso

start: all
	qemu-system-i386 paradoxOS.iso

set-up:
	mkdir -p sysroot/usr
	cp -r kernel/include sysroot/usr/

start_kernel: clean link
	qemu-system-i386 -kernel $(BIN)/paradoxOS.bin


$(BUILD)/boot.o:
	$(AS) kernel/arch/i686/boot.s -o $(BUILD)/boot.o

$(BUILD)/tty.o:
	$(CC) -c kernel/arch/i686/tty.c -o $(BUILD)/basic_vga.o $(CFLAGS)

$(BUILD)/kernel.o:
	$(CC) -c kernel/kernel/kernel.c  -o $(BUILD)/kernel.o $(CFLAGS)

link: $(BUILD)/boot.o $(BUILD)/kernel.o $(BUILD)/tty.o
	$(CC) -T kernel/arch/i686/linker.ld -o $(BIN)/paradoxOS.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/basic_vga.o -lgcc

iso: link
	mkdir -p iso/boot/grub
	cp $(BIN)/paradoxOS.bin iso/boot/paradoxOS.bin
	cp config/grub/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue iso -o paradoxOS.iso

clean:
	rm -r $(BUILD)
	rm -r $(BIN)
	mkdir -p $(BIN)
	mkdir -p $(BUILD)
