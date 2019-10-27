#ifndef SH_H
#define SH_H
#include "../drivers/screen.h"
void user_input(char* input)
{
    if (_strcmp(input, "EXIT") == 0)
    {
        kprint("Exiting...\n");
        asm volatile("hlt");
    }
    else if (_strcmp(input, "CLEAR") == 0)
    {
        clear_screen();
    }
    kprint("\n");
    kprint(input);
    kprint("\n> ");
}
#endif
