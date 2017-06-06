

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
    terminal_write("Hello, kernel World!\nNew line, yay!\n");
    char *words[] = {"one\n","two\n","three\n","4\n","5\n","6\n","7\n"};
    for (int i = 0; i < 5; ++i) {
        for(int j=0; j<5;++j){
                terminal_write(words[j]);
        }
    }
}
