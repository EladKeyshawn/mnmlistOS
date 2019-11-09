
#include "libc/include/stdio.h"
#include "include/tty.h"

void kmain()
{
    tty__cls();
    // note this example will always write to the top
    // line of the screen
    printf("HELLO\nWORLD");

    // infinite loop for now
    while (1)
    {
    }
}