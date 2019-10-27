#include "port.h"

#include <stdint.h>

unsigned char port_byte_in (uint16_t port)
{
	unsigned char res;
	asm("in %%dx, %%al" : "=a" (res) : "d" (port));
	return res;
}

void port_byte_out (uint16_t port, uint8_t data)
{
	asm("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned short port_word_in (uint16_t port)
{
	unsigned short res;
	asm("in %%dx, %%ax" : "=a" (res) : "d" (port));
	return res;
}

void port_word_out (uint16_t port, uint16_t data)
{
	asm("out %%ax, %%dx" : : "a" (data), "d" (port));
}
