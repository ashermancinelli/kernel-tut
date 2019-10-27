#include "timer.h"
#include "isr.h"
#include "port.h"

#include "../libc/stdutil.h"

#include <stdint.h>

uint32_t tick = 0;

static void timer_callback(registers_t *regs)
{
    tick++;
    UNUSED(regs);
}

void init_timer(uint32_t freq)
{
    register_interrupt_handler(IRQ0, timer_callback);

    /*
     * Get the programmable interval timer (PIT)
     * value: hardware clock at 1193180
     */
    uint32_t div = 1193180 / freq;
    uint8_t l = (uint8_t)(div & 0xFF);
    uint8_t h = (uint8_t)((div >> 8) & 0xFF);

    // Send the command
    port_byte_out(0x43, 0x36); /* Command port */
    port_byte_out(0x40, l);
    port_byte_out(0x40, h);
}
