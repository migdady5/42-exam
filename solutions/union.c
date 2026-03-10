#include <unistd.h>

int already_seen(char *s, char c, int end)
{
    int i;

    i = 0;
    while (i < end)
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int len1;

    i = 0;
    len1 = 0;
    if (ac == 3)
    {
        while (av[1][len1])
            len1++;
        while (av[1][i])
        {
            if (!already_seen(av[1], av[1][i], i))
                write(1, &av[1][i], 1);
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (!already_seen(av[1], av[2][i], len1) && !already_seen(av[2], av[2][i], i))
                write(1, &av[2][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
