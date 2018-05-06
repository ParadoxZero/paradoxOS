/* 
 * This file is part of the ParadoxOS (https://github.com/ParadoxZero/paradoxOS).
 * Copyright (c) 2018 Sidhin S Thomas.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/serial.h>
#include<arch/gdt.h>

#include "init_gdt.h"

/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

#define DEBUG

void kernel_main(void) {
    /* Initialize terminal interface */
     #ifdef DEBUG
    init_serial(DEBUG_COM_PORT);
    serial_writeline(DEBUG_COM_PORT,"Kernel Loaded..\n");
    #endif
    terminal_initialize();
    printf("Booting ParadoxOS....\n");
    printf("Setting up Global Descriptor Table.....");
    init_gdt();
    printf("Finished (OK)\n");
    printf("Reloading segment registers to reflect GDT.....");
    reload_segments();
    printf("Finished (OK)\n");

}
