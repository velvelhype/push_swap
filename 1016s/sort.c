#include "push_swap.h"

void    two_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    int     save;

    one = dum->next;
    two = one->next;

    if(one->value > two->value)
    {
        save = one->value;
        one->value = two->value;
        two->value = save;
    }
}

void    three_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    t_list  *three;

    one = dum->next;
    two = one->next;
    three = two->next;

    if(is_sorted(dum) != 1)
    {
    if(one->value > two->value)
    {
        if(two->value > three->value)
            {
                swap(one);
                r_rotate(dum);
            }
        else if (one->value < three->value)
            swap(one);
        else
            rotate(dum);
    }
    else if (one->value < three->value)
        {
            swap(one);
            rotate(dum);
        }
    else
        r_rotate(dum);
    }
}

void    finish_list(t_list  *list)
{
    printf("lets finish\n");
    t_list  *init = list->next;
    init->sort_status = SORTED;
    printf("finish %d\n",init->value);
    if(count_list(list) == 2)
        two_sort(list);
    if(count_list(list) == 3)
        three_sort(list);
}