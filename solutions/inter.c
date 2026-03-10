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

int in_string(char *s, char c)
{
    int i;

    i = 0;
    while (s[i])
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

    i = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            if (!already_seen(av[1], av[1][i], i) && in_string(av[2], av[1][i]))
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
