#ifndef _PARADOX_OS__SERIAL_
#define _PARADOX_OS__SERIAL_

#include <sys/io.h>

#define DEBUG_COM_PORT 0x3F8

void init_serial(uint16_t port);

int serial_received(uint16_t port);

char read_serial(uint16_t port);

int is_transmit_empty(uint16_t port);

void serial_write(uint16_t port, char data);

void serial_writeline(uint16_t port, char* str);

#endif //_PARADOX_OS__SERIAL_