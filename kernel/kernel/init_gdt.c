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


#include "init_gdt.h"
 
extern uint8_t _gdt;
uint8_t *gdt_location;
uint8_t gdt_index=0;

uint16_t create_descriptor(uint32_t base, uint32_t limit, uint16_t flag)
{
    uint64_t descriptor;
 
    // Create the high 32 bit segment
    descriptor  =  limit       & 0x000F0000;         // set limit bits 19:16
    descriptor |= (flag <<  8) & 0x00F0FF00;         // set type, p, dpl, s, g, d/b, l and avl fields
    descriptor |= (base >> 16) & 0x000000FF;         // set base bits 23:16
    descriptor |=  base        & 0xFF000000;         // set base bits 31:24
 
    // Shift by 32 to allow for low part of segment
    descriptor <<= 32;
 
    // Create the low 32 bit segment
    descriptor |= base  << 16;                       // set base bits 15:0
    descriptor |= limit  & 0x0000FFFF;               // set limit bits 15:0
 
    return descriptor;
}

void init_gdt(){
    gdt_location = &_gdt;
    gdt_location[gdt_index++] = create_descriptor(0, 0, 0);
    gdt_location[gdt_index++] = create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    gdt_location[gdt_index++] = create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    gdt_location[gdt_index++] = create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    gdt_location[gdt_index++] = create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));
}