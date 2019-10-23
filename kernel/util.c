void _memcpy(char* src, char* dst, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
        *(dst + i) = *(src + i);
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


}
