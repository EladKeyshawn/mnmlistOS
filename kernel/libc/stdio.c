
#include "../include/tty.h"

int printf(const char* str, ...){
    tty__write_string(4,str);

    return 1;
}