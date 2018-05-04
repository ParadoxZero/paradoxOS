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

#include <stdint.h>

inline static void outb(uint16_t port, uint8_t data){
    asm volatile ( "outb %0, %1" : : "a"(data), "Nd"(port) );
}

inline static uint8_t inb(uint16_t port){
    uint8_t data;
    asm volatile ("inb %1,%0":"=a"(data):"Nd"(port));
    return data;
}