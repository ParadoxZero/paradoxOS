# 
# This file is part of the ParadoxOS (https://github.com/ParadoxZero/paradoxOS).
# Copyright (c) 2018 Sidhin S Thomas.
# 
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

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
