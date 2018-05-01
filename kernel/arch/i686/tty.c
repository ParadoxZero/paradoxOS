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

#include <kernel/tty.h>

#include "basic_vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* vga_buffer;
uint16_t terminal_buffer[TERMINAL_SIZE];

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return (fg | bg << 4);
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}

void terminal_clear(void){
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            vga_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    vga_buffer = (uint16_t*) 0xB8000;
    terminal_clear();
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    vga_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
    if (c == '\n'){
        terminal_row ++;
        terminal_column=0;
        return;
    }
    if (terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        terminal_row ++;
    }
    else {
        terminal_column++ ;
    }
    if (terminal_row > VGA_HEIGHT-1) {
        for (size_t y = 1; y < VGA_HEIGHT; y++) {
            for (size_t x = 0; x < VGA_WIDTH; x++) {
                const size_t index = y * VGA_WIDTH + x;
                const size_t index_less = (y-1) * VGA_WIDTH +x;
                vga_buffer[index_less] = vga_buffer[index];
            }
        }
        terminal_row = VGA_HEIGHT -1;  
         for (size_t x = 0; x < VGA_WIDTH; x++) {
                const size_t index = terminal_row * VGA_WIDTH + x;
                vga_buffer[index] = vga_entry(' ', terminal_color);
            }
    }
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
}

void terminal_write(const char* data) {
    size_t size = strlen(data);
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}