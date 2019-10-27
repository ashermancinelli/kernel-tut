#include "string.h"
#include <stdint.h>

int _strlen(char str[])
{
    int len = 0;
    while (str[len]) ++len;
    return len;
}

void _htoa(int n, char str[])
{
    append(str, '0');
    append(str, 'x');
    char zeros = 0;

    uint32_t tmp;
    int i;
    for (i=28; i > 0; i-=4)
    {
        tmp = (n>>i) & 0xF;
        if (tmp == 0 && zeros == 0)
            continue;
        zeros = 1;
        if (tmp > 0xA)
            append(str, tmp - 0xA + 'a');
        else
            append(str, tmp + '0');
    }

    tmp = n & 0xF;
    if (tmp >= 0xA)
        append(str, tmp - 0xA + 'a');
    else
        append(str, tmp + '0');
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

int _strcmp(char* a, char* b)
{
    int i;
    for (i=0; a[i] == b[i]; i++)
    {
        if (a[i] == '\0') return 0;
    }
    return a[i] - b[i];
}

void append(char s[], int n)
{
    int l = _strlen(s);
    s[l] = n;
    s[l+1] = '\0';
}

void backspace(char s[])
{
    int l = _strlen(s);
    s[l-1] = '\0';
}
