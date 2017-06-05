

default: link

build/boot:
	i686-elf-as src/boot.s -o build/boot.o

build/kernel: build/boot
	i686-elf-gcc -c src/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

link: build/boot build/kernel
	i686-elf-gcc -T src/linker.ld -o bin/myos.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc
