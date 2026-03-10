# 42 Exam (Rank 02) — Easy Solutions

> Quick, minimal versions of common exercises. These are written to be easy to memorize and adapt.

## 1) `ft_swap`
```c
void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
```

## 2) `ft_putstr`
```c
#include <unistd.h>

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}
```

## 3) `ft_strlen`
```c
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
```

## 4) `ft_strcpy`
```c
char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}
```

## 5) `rot13`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    char c;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            c = av[1][i];
            if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
                c += 13;
            else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
                c -= 13;
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 6) `rotone`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char c;

    if (ac == 2)
    {
        while (av[1][i])
        {
            c = av[1][i];
            if (c >= 'a' && c <= 'y')
                c++;
            else if (c == 'z')
                c = 'a';
            else if (c >= 'A' && c <= 'Y')
                c++;
            else if (c == 'Z')
                c = 'A';
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 7) `first_word`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            write(1, &av[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}
```

## 8) `search_and_replace`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 4 && !av[2][1] && !av[3][1])
    {
        while (av[1][i])
        {
            if (av[1][i] == av[2][0])
                av[1][i] = av[3][0];
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 9) `ulstr`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char c;

    if (ac == 2)
    {
        while (av[1][i])
        {
            c = av[1][i];
            if (c >= 'a' && c <= 'z')
                c -= 32;
            else if (c >= 'A' && c <= 'Z')
                c += 32;
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 10) `ft_atoi`
```c
int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        res = res * 10 + (str[i++] - '0');
    return (res * sign);
}
```

## 11) `ft_strcmp`
```c
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```

## 12) `ft_strrev`
```c
char    *ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[j])
        j++;
    j--;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}
```

## 13) `inter`
```c
#include <unistd.h>

int seen(char *s, char c, int end)
{
    int i = 0;
    while (i < end)
        if (s[i++] == c)
            return (1);
    return (0);
}

int in_str(char *s, char c)
{
    int i = 0;
    while (s[i])
        if (s[i++] == c)
            return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 3)
    {
        while (av[1][i])
        {
            if (!seen(av[1], av[1][i], i) && in_str(av[2], av[1][i]))
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 14) `wdmatch`
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;

    if (ac == 3)
    {
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }
        if (!av[1][i])
            write(1, av[1], i);
    }
    write(1, "\n", 1);
    return (0);
}
```

## 15) `union`
```c
#include <unistd.h>

int seen(char *s, char c, int end)
{
    int i = 0;
    while (i < end)
        if (s[i++] == c)
            return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i;

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            if (!seen(av[1], av[1][i], i))
                write(1, &av[1][i], 1);
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (!seen(av[1], av[2][i], ft_strlen(av[1]))
                && !seen(av[2], av[2][i], i))
                write(1, &av[2][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

> For `union`, either add your own `ft_strlen` or replace `ft_strlen(av[1])` with a small loop.

## 16) `ft_list_size`
```c
typedef struct s_list
{
    struct s_list *next;
    void          *data;
} t_list;

int ft_list_size(t_list *begin_list)
{
    int n = 0;
    while (begin_list)
    {
        n++;
        begin_list = begin_list->next;
    }
    return (n);
}
```

## 17) `ft_range`
```c
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *arr;
    int len;
    int i;

    if (start == end)
        return (NULL);
    len = (start < end) ? end - start : start - end;
    arr = (int *)malloc(sizeof(int) * len);
    if (!arr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        arr[i] = start;
        start += (start < end) ? 1 : -1;
        i++;
    }
    return (arr);
}
```

## 18) `ft_itoa`
```c
#include <stdlib.h>

static int len_num(int n)
{
    int len = (n <= 0);
    while (n)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    long n = nbr;
    int len = len_num(nbr);
    char *s = (char *)malloc(len + 1);

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
        s[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (s);
}
```

## 19) `ft_list_foreach`
```c
typedef struct s_list
{
    struct s_list *next;
    void          *data;
} t_list;

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}
```

## 20) `split`
```c
#include <stdlib.h>

int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *s)
{
    int i = 0, n = 0;
    while (s[i])
    {
        while (s[i] && is_sep(s[i]))
            i++;
        if (s[i])
            n++;
        while (s[i] && !is_sep(s[i]))
            i++;
    }
    return (n);
}

char *dup_word(char *s, int start, int end)
{
    char *w;
    int i = 0;

    w = (char *)malloc(end - start + 1);
    if (!w)
        return (NULL);
    while (start < end)
        w[i++] = s[start++];
    w[i] = '\0';
    return (w);
}

char    **ft_split(char *str)
{
    int i = 0, j, k = 0, words = count_words(str);
    char **out = (char **)malloc(sizeof(char *) * (words + 1));

    if (!out)
        return (NULL);
    while (k < words)
    {
        while (str[i] && is_sep(str[i]))
            i++;
        j = i;
        while (str[i] && !is_sep(str[i]))
            i++;
        out[k++] = dup_word(str, j, i);
    }
    out[k] = NULL;
    return (out);
}
```

## 21) `ft_list_remove_if`
```c
#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    void          *data;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *tmp;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
    while (*begin_list && (*begin_list)->next)
    {
        if (cmp((*begin_list)->next->data, data_ref) == 0)
        {
            tmp = (*begin_list)->next;
            (*begin_list)->next = tmp->next;
            free(tmp);
        }
        else
            *begin_list = (*begin_list)->next;
    }
}
```

## 22) `sort_list`
```c
typedef struct s_list
{
    struct s_list *next;
    int           data;
} t_list;

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *cur;
    int swapped = 1;

    if (!lst)
        return (lst);
    while (swapped)
    {
        swapped = 0;
        cur = lst;
        while (cur->next)
        {
            if (!cmp(cur->data, cur->next->data))
            {
                tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }
    }
    return (lst);
}
```

---

If you want, I can also give you a **one-file-per-exercise version** ready to compile with `gcc -Wall -Wextra -Werror`.
