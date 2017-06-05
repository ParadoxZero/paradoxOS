#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "basic_vga.h"

/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void) {
    /* Initialize terminal interface */
    terminal_initialize();

    /* Newline support is left. */
    terminal_writestring("Hello, kernel World!\nNew line, yay!\n");
}
