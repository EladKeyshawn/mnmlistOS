#include "include/vga.h"
#include "libc/include/stdint.h"

volatile char *video = (volatile char *)0xB8000;
uint16_t SCREEN_WIDTH = 80; // should be 320, idk for now
uint16_t SCREEN_HEIGHT = 240;

uint16_t terminal_x_idx = 0;
uint16_t terminal_y_idx = 0;


void tty__new_line(){
    terminal_y_idx++;
    terminal_x_idx = 0;
}

void tty__cls() {
    for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++)
    {
        uint16_t* cursor = ((uint16_t*) video) + i;
        *cursor = vga_entry('\0', VGA_COLOR_BLACK);
    }
}

void tty__write_string(enum vga_color color, const char *string)
{
    
    while (*string != 0)
    {
        uint16_t* cursor = ((uint16_t*) video) + (terminal_y_idx * SCREEN_WIDTH) + terminal_x_idx;

        if (*string == '\n') {
            tty__new_line();
            string++;
            continue;
        }

        *cursor++ = vga_entry(*string++, color);
        
        if(terminal_x_idx == 320) {
            terminal_x_idx = 0;
            terminal_y_idx++;
        } 
        else {
            terminal_x_idx++;
        }
    }
}



