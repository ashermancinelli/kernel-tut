#include "port.h"

unsigned char port_byte_in (uint16_t port)
{
	unsigned char res;
	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));
	return res;
}

void port_byte_out (uint16_t port, uint8_t data)
{
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned char port_word_in (uint16_t port)
{
	unsigned short res;
	__asm__ ("in %%dx, %%ax" : "=a" (res) : "d" (port));
	return res;
}

void port_word_out (uint16_t port, uint16_t data)
{
	__asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}
