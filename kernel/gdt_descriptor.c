#include "libc/include/stdint.h"
#include "include/gdt.h"

struct gdt_desc {
    uint16_t lim0_15;
    uint16_t base0_15;
    uint8_t base16_23;
    uint8_t acces;
    uint8_t lim16_19:4;
    uint8_t flags:4;
    uint8_t base24_31;
} __attribute__((packed));

struct gdtr {
    uint16_t limit; // size of gdt table
    uint32_t base; // address of gdt table
}__attribute__((packed));

struct gdt_desc GDT[3];
struct gdtr gdtr;


void init_gdt_desc(uint32_t base, uint32_t limite, uint8_t acces, uint8_t flags, struct gdt_desc *desc)
{
    desc->lim0_15 = (limite & 0xffff);
    desc->base0_15 = (base & 0xffff);
    desc->base16_23 = (base & 0xff0000) >> 16;
    desc->acces = acces;
    desc->lim16_19 = (limite & 0xf0000) >> 16;
    desc->flags = (flags & 0xf);
    desc->base24_31 = (base & 0xff000000) >> 24;
    return;
}
void init_gdt() {
    init_gdt_desc(0, 0, 0,0, &GDT[0]);

    init_gdt_desc(0x0, 0xFFFFFFFF, 0x9A,0xC,&GDT[1]); /* kernel code */
    init_gdt_desc(0x0, 0xFFFFFFFF, 0x92,0xC, &GDT[2]); /* kernel stack */

    gdtr.limit = (uint16_t) (sizeof(struct gdt_desc) * 3) - 1;;
    gdtr.base = (uint32_t) &GDT;
    
    flush_gdt((uint32_t) &gdtr);
}