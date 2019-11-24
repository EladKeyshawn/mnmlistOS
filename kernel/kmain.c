
#include "include/tty.h"
#include "include/gdt_descriptor.h"
#include "include/serial.h"

#include "libc/include/stdio.h"
#include "libc/include/stdint.h"


void kmain()
{

    tty__cls(); // clear screen


    // notice we're in protected mode already here
    
    // disable interrupts


    init_gdt();
    puts("GDT initialized\n");

    // initialize serial output
    init_serial();
    puts("Serial COM1 initialized\n");
    serial_puts("Serial COM1 Log");

    // initialize IDT


    // infinite loop for now
    while (1)
    {
    }
}