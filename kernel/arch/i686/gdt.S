# This is the function definition of function
#   setGDT( void* location, uint16_t size)
#   @file arch/include/gdt.h
#
.section .data
.align 16
gdtr: 
    .short 0 # 2 Byte - (DW - 2 Bytes) For limit storage
    .long 2 # 4 Bytes - (DD - 4 Bytes) For base storage
jump_addr:
    .short 0 # Offset
    .short 0 # segment_addres 

.section .text
.global set_gdt
.type set_gdt @function

set_gdt:
   mov   -4(%esp), %eax
   mov   %eax, gdtr + 2 
   mov    -8(%esp), %ax
   mov   %ax, gdtr
   lgdt  gdtr
   #call reload_segments
   ret

reload_segments:
    jmp $0x08,$reload_cs
reload_cs:
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    ret
