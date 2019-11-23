
#include "../include/tty.h"
#include "../include/vga.h"

int puts(const char* str){
    tty__write_string(vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK),str);

    return 1;
}