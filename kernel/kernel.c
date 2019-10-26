
#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "util.h"

void main()
{
    isr_install();
    clear_screen();
    kprint("Welcome to Aos\n");
    __asm__ __volatile__("int $2");
}
