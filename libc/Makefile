CC	:= $(OCC)
AS	?= $(HOST)-as
AR	?= $(HOST)-ar

CFLAGS 		?= # -02 -g
CPPFLAGS 	?=
LDFLAGS		?=

LIBS ?=

DESTDIR		:= $(SYSROOT)
PREFIX		:=$(SYSROOT)/usr
EXEC_PREFIX	:=$(PREFIX)
INCLUDEDIR	:=$(PREFIX)/include
LIBDIR		:=$(EXEC_PREFIX)/lib

CFLAGS			:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS		:=$(CPPFLAGS) -D__is_libc -Iinclude
LIBK_CFLAGS		:=$(CFLAGS)	-D__is_libk
LIBK_CPPFLAGS	:=$(CPPFLAGS) -D__is_libk

ARCHDIR	:= arch/$(HOST)
BIN			:= bin
BUILDDIR	:= build

include $(ARCHDIR)/make.config

CFLAGS			:=$(CFLAGS) $(ARCH_CFLAGS)
CPPFLAGS		:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CFLAGS		:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBK_CPPFLAGS	:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

LIBC := .libc
LIBK := .libk

MODULES := stdio stdlib string 
FREE_SOURCE :=\
$(ARCH_FREE_SOURCE) \
string/strlen.c 	\
string/memcpy.c		\
string/memcmp.c		\
string/memmove.c	\
string/memset.c		\
stdlib/abort.c		\
stdio/printf.c		\
stdio/putchar.c		\
stdio/puts.c		\

HOSTED_SOURCE :=\
$(ARCH_HOSTED_SOURCE)

SOURCE :=\
$(FREE_SOURCE) \
$(HOSTED_SOURCE)

LIBK_TARGETS := $(FREE_SOURCE:.c=.libk.o)
LIBK_OBJS :=  $(addprefix $(BUILDDIR)/, $(LIBK_TARGETS))

# LIBC_OBJS := $() Later when lib c is buildable

BINARIES := libk.a

.PHONY: clean init

default: init

install: init install-headers install-libs

all: $(BINARIES)

init:
	for MODULE in $(MODULES); do mkdir -p $(BUILDDIR)/$$MODULE; done
	mkdir -p $(BIN)
	mkdir -p $(BUILDDIR)
	mkdir -p $(BUILDDIR)/$(ARCHDIR)
	mkdir -p $(SYSROOT)
	mkdir -p $(INCLUDEDIR)
	mkdir -p $(LIBDIR)

install-headers:
	cp -r include/* $(INCLUDEDIR)
install-libs: all
	for BINARY in $(BINARIES); do cp $(BIN)/$$BINARY $(LIBDIR)/; done
clean:
	rm -r $(BUILDDIR)
	rm -r $(BIN)

libk.a: $(LIBK_TARGETS)
	$(AR) rcs $(BIN)/$@ $(LIBK_OBJS)

%.libk.o: %.c
	$(CC) -c $< -o $(BUILDDIR)/$@ $(LIBK_CFLAGS)
