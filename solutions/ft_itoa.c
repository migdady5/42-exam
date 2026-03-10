#include <stdlib.h>

static int  nbr_len(long n)
{
    int len;

    len = (n <= 0);
    while (n)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    long n;
    int len;
    char *s;

    n = nbr;
    len = nbr_len(n);
    s = (char *)malloc(len + 1);
    if (!s)
        return (NULL);
    s[len] = '\0';
    if (n == 0)
        s[0] = '0';
    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }
    while (n > 0)
    {
        s[--len] = (char)((n % 10) + '0');
        n /= 10;
    }
    return (s);
}
