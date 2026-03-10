typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swapped;
    int tmp;
    t_list *cur;

    if (!lst)
        return (lst);
    swapped = 1;
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
