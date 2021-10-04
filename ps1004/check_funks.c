#include "push_swap.h"

int    is_sorted(t_list *a)
{
    t_list *cur;
    t_list *nxt;

    cur = a->next;
    nxt = cur->next;
    while(cur->value < nxt->value && cur->dum_check == 0)
    {
        cur = cur->next;
        nxt = nxt->next;
        if (nxt->dum_check == 1)
            return 1;
    }
    return 0;
};

void stack_check(t_list *a_dummy, t_list *b_dummy)
{
    printf("gonna check the a_stacks\n");
    a_dummy = a_dummy->next;
    while(a_dummy->dum_check != 1)
    {
        printf("%d\n",a_dummy->value);
        a_dummy = a_dummy->next;
    }
    printf("gonna check the b_stacks\n");
    b_dummy = b_dummy->next;
    while(b_dummy->dum_check != 1)
    {
        printf("%d\n", b_dummy->value);
        b_dummy = b_dummy->next;
    }
}

int count_list(t_list *list)
{
    int count;
    count = 0;
    list = list->next;
    while(!list->dum_check)
    {
        count++;
        list = list->next;
    }
    printf("count is %d\n", count);
    return(count);
}