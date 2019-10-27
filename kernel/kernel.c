#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"
#include "../drivers/screen.h"

/*
 * This was renamed from 'main' because gcc
 * sees 'main' as a keyword and would cause 
 * error/warnings/strange behavior.
 *
 * In boot/kernel_entry.asm, the main point is
 * defined as the external kernel_main function
 * inside the _start label.
 */
void kernel_main()
{
    isr_install();
    irq_install();
    clear_screen();
    kprint("Welcome to DOCos.\n> ");
}

