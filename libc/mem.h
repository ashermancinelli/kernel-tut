#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define low_16(address)     (uint16_t)((address) & 0xFFFF)
#define high_16(address)    (uint16_t)(((address) >> 16) & 0xFFFF)
extern void _memcpy(char* src, char* dst, int nbytes);
extern void _memset(uint8_t *dst, uint8_t val, uint32_t len);
extern uint32_t kmalloc(uint32_t size, int align, uint32_t *addr);
#endif
