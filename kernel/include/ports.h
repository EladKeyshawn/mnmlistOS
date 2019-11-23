#ifndef _PORTS_H
#define _PORTS_H
#include "../libc/include/stdint.h"


void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);


#endif