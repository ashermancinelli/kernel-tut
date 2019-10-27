#ifndef UTIL_H
#define UTIL_H
#include <stdint.h>
#define low_16(address)     (uint16_t)((address) & 0xFFFF)
#define high_16(address)    (uint16_t)(((address) >> 16) & 0xFFFF)
extern void _memcpy(char* src, char* dst, int nbytes);
extern void _itoa(int n, char str[]);
extern int _strlen(char* str);
extern void _memset(uint8_t *dst, uint8_t val, uint32_t len);
extern void reverse(char s[]);
#endif
