#ifndef _PARADOX_OS_ARCH_GDT_
#define _PARADOX_OS_ARCH_GDT_
#include <stdint.h>

typedef uint64_t gdt_t;

void set_gdt(void * gdt_location, uint16_t size);

void reload_segments();
#endif //_PARADOX_OS_ARCH_GDT_