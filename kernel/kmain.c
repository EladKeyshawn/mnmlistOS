
#include "libc/include/stdio.h"
#include "include/tty.h"
#include "libc/include/stdint.h"
#include "include/gdt_descriptor.h"

void kmain()
{

    tty__cls(); // clear screen


    // notice we're in protected mode here
    
    // disable interrupts


    init_gdt();
    printf("GDT initialized");



    // infinite loop for now
    while (1)
    {
    }
}