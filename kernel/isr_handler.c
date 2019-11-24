#include "include/isr.h"
#include "libc/include/stdio.h"

void isr_handler(isr_state_t state) {
    
    switch (state.int_no)
    {
    case 1:
        puts("keyboard interrupt");
   
    default:
        break;
    }
}