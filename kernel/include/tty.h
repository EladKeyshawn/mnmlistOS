#ifndef _TTY_H
#define _TTY_H

void tty__write_string(int colour, const char *string);
void tty__new_line();
void tty__cls();

#endif