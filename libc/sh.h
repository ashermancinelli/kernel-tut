#ifndef SH_H
#define SH_H
#include "../drivers/screen.h"
#include "string.h"

#include <stdint.h>

#define CLEAR_HDL 0
#define EXIT_HDL 1

/*
 * Currently a command handler cannot function with
 * arguments.
 *
 * TODO: implement a more developed parser
 * to handle arguments and more complex tasks, after
 * a filesystem is developed.
 */

// void (*handlers[256])();

void clear_hdl()
{
    clear_screen();
}

void exit_hdl()
{
    kprint("Exiting...\n");
    asm volatile("hlt");
}

void page_hdl()
{
    uint32_t addr;
    uint32_t page = kmalloc(1000, 1, &addr);
    char page_str[16] = "";
    _htoa(page, page_str);
    char phys_str[16] = "";
    _htoa(addr, phys_str);
    kprint("Page: ");
    kprint(page_str);
    kprint(", physical address: ");
    kprint(phys_str);
    kprint("\n");
}


// handlers[EXIT_HDL] = exit_hdl;
// handlers[CLEAR_HDL] = clear_hdl;

static uint8_t line_number = 0;

void user_input(char* input)
{
    line_number++;
    if (_strcmp(input, "EXIT") == 0)
        exit_hdl();
    else if (_strcmp(input, "CLEAR") == 0)
        clear_hdl();
    else if (_strcmp(input, "PAGE") == 0)
        page_hdl();

    kprint(input);
    kprint("\n");

    char str[5];
    _itoa(line_number, str);
    kprint(str);
    kprint(" > ");
}
#endif
