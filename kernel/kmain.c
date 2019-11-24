
#include "include/tty.h"
#include "include/gdt_descriptor.h"
#include "include/serial.h"
#include "include/idt.h"
#include "include/pic.h"

#include "libc/include/stdio.h"
#include "libc/include/stdint.h"


void kmain()
{

    tty__cls(); // clear screen


    // notice we're in protected mode already here
    
    // disable interrupts


    init_gdt();
    puts("init GDT \n");

    // initialize serial output
    init_serial();
    puts("init Serial COM1\n");
    serial_puts("Serial COM1 Log");

    // initialize IDT
    idt_init();
    puts("init IDT\n");


    // initialize PIC
    pic_init();
    puts("init PIC");


    // infinite loop for now
    while (1)
    {
    }
}