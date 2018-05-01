

#include <tty.h>

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

    terminal_write("Welcome to Paradox OS\n");
    terminal_write("Nice to meet you.\n");
}
