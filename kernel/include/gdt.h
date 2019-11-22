#ifndef _GDT_H
#define _GDT_H


#include "../libc/include/stdint.h"

// base address of GDT tagle, limit - size of table
void set_gdt(uint32_t gdtr_ptr);

#endif