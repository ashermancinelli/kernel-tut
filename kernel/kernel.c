#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"
#include "../drivers/screen.h"

void kernel_main()
{
    isr_install();
    irq_install();
    clear_screen();
    kprint("Welcome to DOCos.\n> ");
}

