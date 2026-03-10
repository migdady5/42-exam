#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *arr;
    int len;
    int i;

    if (start == end)
        return (NULL);
    len = (start < end) ? (end - start) : (start - end);
    arr = (int *)malloc(sizeof(int) * len);
    if (!arr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        arr[i] = start;
        if (start < end)
            start++;
        else
            start--;
        i++;
    }
    return (arr);
}
