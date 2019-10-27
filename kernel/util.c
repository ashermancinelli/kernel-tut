#include "util.h"

void _memcpy(char* src, char* dst, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
        *(dst + i) = *(src + i);
}

int _strlen(char* str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void _itoa(int n, char str[])
{
    int i=0, sign;
    if ((sign = n) < 0) n = -n;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign<0) str[i++] = '-';
    str[i] = '\0';
    reverse(str);
}

void _memset(uint8_t *dst, uint8_t val, uint32_t len)
{
    uint8_t *temp = (uint8_t *)dst;
    for ( ; len != 0; len--) *temp++ = val;
}

void reverse(char s[])
{
    int c, j, i;
    for (i = 0, j = _strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
