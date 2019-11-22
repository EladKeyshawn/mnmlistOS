
#include "libc/include/stdio.h"
#include "include/tty.h"
#include "libc/include/stdint.h"
#include "include/gdt.h"


struct gdt_desc {
    uint16_t lim0_15;
    uint16_t base0_15;
    uint8_t base16_23;
    uint8_t acces;
    uint8_t lim16_19:4;
    uint8_t other:4;
    uint8_t base24_31;
} __attribute__((packed));

struct gdtr {
    uint16_t limit; // size of gdt table
    uint32_t base; // address of gdt table
}__attribute__((packed));

struct gdt_desc GDT[256];
struct gdtr gdtr;


void init_gdt_desc(uint32_t base, uint32_t limite, uint8_t acces, uint8_t other, struct gdt_desc *desc)
{
    desc->lim0_15 = (limite & 0xffff);
    desc->base0_15 = (base & 0xffff);
    desc->base16_23 = (base & 0xff0000) >> 16;
    desc->acces = acces;
    desc->lim16_19 = (limite & 0xf0000) >> 16;
    desc->other = (other & 0xf);
    desc->base24_31 = (base & 0xff000000) >> 24;
    return;
}
void init_gdt() {
    init_gdt_desc(0, 0, 0,0, &GDT[0]);
    init_gdt_desc(0x0, 0x3FFFFF, 0x9A,0,&GDT[1]); /* kernel code */
    init_gdt_desc(0x0, 0x3FFFFF, 0x92,0, &GDT[2]); /* kernel stack */

    gdtr.limit = (uint16_t) sizeof(GDT);
    gdtr.base = (uint32_t) &GDT;
    set_gdt((uint32_t) &gdtr);
}

void kmain()
{

    tty__cls();
    // note this example will always write to the top
    // line of the screen
    printf("HELLO\nWORLD");

    // initialize memory space
    // first lets notice we're in protected mode here
    
    // disable interrupts

    // init GDT
    init_gdt();
    
    printf("HELLO\nWORLD");


    // infinite loop for now
    while (1)
    {
    }
}