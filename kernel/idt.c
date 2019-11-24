#include "libc/include/stdint.h"
#include "include/isr.h"

typedef struct idt_desc {
   uint16_t offset_1; // offset bits 0..15
   uint16_t selector; // a code segment selector in GDT or LDT
   uint8_t zero;      // unused, set to 0
   uint8_t type_attr; // type and attributes, see below
   uint16_t offset_2; // offset bits 16..31
} __attribute__((packed)) idt_desc_t ;

idt_desc_t idt_table[256];


idt_desc_t create_idt_entry(uint32_t handler_address, uint16_t cs_selector,
uint8_t privilege, uint8_t used, uint8_t type) {
     idt_desc_t entry;

     entry.offset_1 = handler_address & 0xFFFF << 16;
     entry.offset_2 = handler_address & 0xFFFF;
     entry.selector = cs_selector;
     entry.zero = 0;
     entry.type_attr = 0;
     entry.type_attr |= used == 1? 0b10000000: 0;
     entry.type_attr |= (type & 0xF);
     entry.type_attr |= (privilege & 0x3) << 5;

     return entry;
}

void idt_init() {
    idt_table[1] = create_idt_entry((uint32_t) &isr1, 0x8, 0, 1, 0xE );
}



