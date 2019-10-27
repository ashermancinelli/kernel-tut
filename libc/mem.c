#include "mem.h"

#include <stdint.h>

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
