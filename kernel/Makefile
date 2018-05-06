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
OBJCPY := $(TARGET)-objcopy

CFLAGS	:= $(CFLAGS) --std=gnu99 -ffreestanding -O2 -Wall -Wextra -nostdlib -g

LIBS	:= -lgcc -lk

ARCHDIR		:= arch/$(HOST)
KERNELDIR	:= kernel
BIN			:= bin
BUILDDIR	:= build

INCLUDEDIRS =\
arch/include 

CC := $(CC) -I$(INCLUDEDIRS)

KERNEL_SOURCE_FILES = \
kernel.c \
init_gdt.c \
serial.c

KERNEL_SOURCE = $(addprefix $(KERNELDIR)/,$(KERNEL_SOURCE_FILES))

C_SOURCE :=\
$(ARCHDIR)/tty.c \
$(KERNEL_SOURCE)

A_SOURCE :=\
$(ARCHDIR)/boot.S \
$(ARCHDIR)/gdt.S


OBJ_NAMES := $(C_SOURCE:.c=.o) $(A_SOURCE:.S=.o)
OBJS := $(addprefix $(BUILDDIR)/, $(OBJ_NAMES))

CRTI_OBJ=$(ARCHDIR)/crti.o
CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=$(ARCHDIR)/crtn.o


.PHONY: clean init

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

$(KERNEL_NAME).bin: $(OBJ_NAMES) $(CRTI_OBJ) $(CRTN_OBJ)
	$(CC) $(CFLAGS) -T $(ARCHDIR)/linker.ld -o $(BIN)/$@ $(BUILDDIR)/$(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OBJS) $(LIBS) $(CRTEND_OBJ) $(BUILDDIR)/$(CRTN_OBJ) 
	grub-file --is-x86-multiboot $(BIN)/$@

%.o: %.S
	$(AS) -g $< -o $(BUILDDIR)/$@

%.o: %.c
	$(CC) -c $< -o $(BUILDDIR)/$@ $(CFLAGS)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(BIN)
