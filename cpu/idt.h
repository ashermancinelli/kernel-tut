#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// Segment selectors
#define KERNEL_CS 0x08

// Define every interrupt gate handler
typedef struct
{
    // l16 bits of handler function address
    uint16_t low_offset;

    // Kernel segment selector
    uint16_t sel;

    uint8_t always0;

    /*
     * First byte
     * bit 7    <- interrupt is preset
     * bis 6-5  <- caller priv level
     * bit 4    <- set to 0 for interrupt gates
     * bit 3-0  <- 1110 = decimal 14 = 32 bit interrupt gate
     */
    uint8_t flags;
    uint16_t high_offset;
} __attribute__((packed)) idt_gate_t;

typedef struct
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

// idt.c
void set_idt_gate(int n, uint32_t handler);
void set_idt();

#endif
