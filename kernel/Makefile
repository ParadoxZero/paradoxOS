
KERNEL_NAME		:= paradoxOS
KERNEL_DEST 	:= $(SYSROOT)/boot

CC	:= $(OCC)
AS	:= $(OAS)

CFLAGS	:= $(CFLAGS) --std=gnu99 -ffreestanding -O2 -Wall -Wextra -nostdlib

LIBS	:= -lgcc 

ARCHDIR		:= arch/$(HOST)
KERNELDIR	:= kernel
BIN			:= bin
BUILDDIR	:= build

KERNEL_SOURCE = \
$(KERNELDIR)/kernel.c

C_SOURCE :=\
$(ARCHDIR)/tty.c \
$(KERNEL_SOURCE)

A_SOURCE :=\
$(ARCHDIR)/boot.S

OBJ_NAMES := $(C_SOURCE:.c=.o) $(A_SOURCE:.S=.o)
OBJS := $(addprefix $(BUILDDIR)/, $(OBJ_NAMES))


.PHONY: clean

.SUFFIXES: .o .c .S

default: all

install: all
	mkdir -p $(SYSROOT)/boot
	cp $(BIN)/$(KERNEL_NAME).bin $(SYSROOT)/boot/	

all: init $(KERNEL_NAME).bin

init:
	mkdir -p $(BIN)
	mkdir -p $(BUILDDIR)
	mkdir -p $(BUILDDIR)/$(ARCHDIR)
	mkdir -p $(BUILDDIR)/$(KERNELDIR)
	mkdir -p $(SYSROOT)
	mkdir -p $(SYSROOT)/usr/include
	cp -r include/* $(SYSROOT)/usr/include

$(KERNEL_NAME).bin: $(OBJ_NAMES)
	$(CC) -T $(ARCHDIR)/linker.ld -o $(BIN)/$@ $(CFLAGS) $(OBJS) $(LIBS)
	grub-file --is-x86-multiboot $(BIN)/$@

%.o: %.S
	$(AS) $< -o $(BUILDDIR)/$@

%.o: %.c
	$(CC) -c $< -o $(BUILDDIR)/$@ $(CFLAGS)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(BIN)
