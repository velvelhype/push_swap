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

void  recursive_sort(t_list *a_dum, t_list *b_dum)
{
    t_list *list_b = b_dum->next;


    int std = list_b->value;
    printf("rec :std %d\n", std);
    rotate(b_dum);
    list_b = b_dum->next;
    while(list_b->value != std)
    {
        if(list_b->value > std)
            push(b_dum, a_dum);
        rotate(b_dum);
        list_b = b_dum->next;
    }
    if (count_list(b_dum) > 3)
    {
        push(b_dum, a_dum);
        recursive_sort(a_dum, b_dum);
    }
    stack_check(a_dum, b_dum);
}

void  first_sort(t_list *a_dum, t_list *b_dum)
{
    t_list *list_a = a_dum->next;

    int std = list_a->value;
    rotate(a_dum);
    list_a = a_dum->next;
    int count;
    printf("value is %d\n", std);
    while(list_a->value != std)
    {
        printf("checki'n %d\n", list_a->value);
        if(list_a->value < std)
        {
            push(a_dum, b_dum);
        }
        else
        {
            rotate(a_dum);
        }
        list_a = a_dum->next;
    }
    stack_check(a_dum, b_dum);
    count = count_list(b_dum);
    if (count > 3)
        recursive_sort(a_dum, b_dum);
    if(count == 3)
            three_sort(b_dum);
    else if(count == 2)
            two_sort(b_dum);
    
    while(count--)
    {
        push(b_dum, a_dum);
        rotate(a_dum);
    }
    printf("end\n");
    stack_check(a_dum, b_dum);
}

int     main(int argc, char **argv)
{
    t_list  *a_dummy = malloc(sizeof(t_list));
    t_list  *b_dummy = malloc(sizeof(t_list));
    t_list  *a_stack = malloc(sizeof(t_list));
    int c = 1;

    while(*(argv + c))
    {
        if(c == 1)
        {
            create(a_stack, a_dummy, ft_atoi(*(argv + c)));
            b_dummy_set(b_dummy);
        }
        else
            append(a_stack, a_dummy, ft_atoi(*(argv + c)));
        c++;
    }
    first_sort(a_dummy, b_dummy);
    //ra_check(a_dummy, b_dummy);
}