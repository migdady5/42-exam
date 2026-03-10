#include <stdlib.h>

int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *s)
{
    int i;
    int n;

    i = 0;
    n = 0;
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

char    *dup_word(char *s, int start, int end)
{
    char *word;
    int i;

    word = (char *)malloc(end - start + 1);
    if (!word)
        return (NULL);
    i = 0;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int words;
    char **out;

    i = 0;
    k = 0;
    words = count_words(str);
    out = (char **)malloc(sizeof(char *) * (words + 1));
    if (!out)
        return (NULL);
    while (k < words)
    {
        while (str[i] && is_sep(str[i]))
            i++;
        j = i;
        while (str[i] && !is_sep(str[i]))
            i++;
        out[k] = dup_word(str, j, i);
        if (!out[k])
            return (NULL);
        k++;
    }
    out[k] = NULL;
    return (out);
}
