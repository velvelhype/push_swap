#include "push_swap.h"

int    is_sorted(t_list *a)
{
    t_list *cur;
    t_list *nxt;

    cur = a->next;
    nxt = cur->next;
    while(cur->value < nxt->value && cur->is_dummy == FALSE)
    {
        cur = cur->next;
        nxt = nxt->next;
        if (nxt->is_dummy == TRUE)
            return 1;
    }
    return 0;
};

void    print_sort_status(t_list *list)
{
    if(list->sort_status != UNKNOWN)
        {
            if(list->sort_status == SORTED)
                printf("S");
            else if(list->sort_status == CHUNK)
                printf("C");
        }
    else
        printf("U");
}

void    stack_check(t_list *a_dummy, t_list *b_dummy)
{
    printf("a\t\tb\n");
    printf("=========================\n");
    int a_end = 0;
    int b_end = 0;
    a_dummy = a_dummy->next;
    b_dummy = b_dummy->next;
    while ((a_dummy->is_dummy == FALSE || b_dummy->is_dummy == FALSE) && (a_end == FALSE || b_end == FALSE))
    {
        // printf("%d         %d         \n", a_dummy->value, b_dummy->value);
        if(a_dummy->value == 0 || a_end == TRUE)
        {
            printf("%c\t", '-');
            a_end = TRUE;
        }
        else
            printf("%d\t", a_dummy->value);
        print_sort_status(a_dummy);
        if(b_dummy->value == 0 || b_end == TRUE)
        {
            printf("\t%c\t", '-');
            b_end = TRUE;
        }
        else
            printf("\t%d\t", b_dummy->value);
        print_sort_status(b_dummy); 
        printf("\n"); 
        a_dummy = a_dummy->next;
        b_dummy = b_dummy->next;
    }
}

void illegal_stack_check(t_list *a_dummy)
{
    a_dummy = a_dummy->next;
    while(a_dummy->is_dummy == FALSE)
    {
        printf("%d\n",a_dummy->value);
        a_dummy = a_dummy->next;
    }
}

int count_list(t_list *list)
{
    int count = 0;

    list = list->next;
    while(list->is_dummy == FALSE)
    {
        count++;
        list = list->next;
    }
    return(count);
}