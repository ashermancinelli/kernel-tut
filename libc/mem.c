#include "mem.h"

#include <stdint.h>
#include <stddef.h>

void _memcpy(char* src, char* dst, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
        *(dst + i) = *(src + i);
}

void _memset(uint8_t *dst, uint8_t val, uint32_t len)
{
    uint8_t *temp = (uint8_t *)dst;
    for ( ; len != 0; len--) *temp++ = val;
}

static uint32_t free_mem_addr = 0x10000;

uint32_t kmalloc(size_t size, int align, uint32_t *addr)
{
    if (align == 1 && (free_mem_addr & 0xFFFFF000))
    {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }

    if (addr)
        *addr = free_mem_addr;

    uint32_t ret = free_mem_addr;
    free_mem_addr += size;
    return ret;
}
