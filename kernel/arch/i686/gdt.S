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

.section .bss
gdtr: 
g_l: .short 0
g_b: .long 0

.section .text
.global set_gdt, set_gdt_asm, reload_segments
.type set_gdt @function
.type reload_segments @function

# This function will load the GDT using the parameters provided
# to stack and then reload the segment registers.
#
# The function prototype is available at @ref arch/include/gdt.h
set_gdt:
    push %ebp
    mov  %esp, %ebp
    movl 8(%ebp), %eax   /* Move value of parameter 1(pointer to GDT) into EAX. | 8byte- Double Word/long */
    movl %eax, g_b 
    movl 12(%ebp), %ax   /* Move value of parameter 2(Size of GDT) into EAX. | 4byte- Word/short */
    movw %ax, g_l
    lgdt gdtr
    pop %ebp
    ret



# This function will repload the segment registers
# to reflext upon the changes.
#
# Function prototype @ref arch/include/gdt.h
reload_segments:
    mov %eax, %cr0
    or %al, 1
    mov %cr0, %eax
    jmp $0x08,$reload_cs # Long jump will reload the CS
reload_cs:
    mov $0x10, %ax
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ds
    mov %ax, %ss
    ret
