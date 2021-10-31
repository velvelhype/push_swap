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

void baka_sort(t_list   *a_dummy)
{
    t_list  *one_list;
    t_list  *two_list;
    int     stock;

    one_list = a_dummy;
    one_list = one_list->next;
    two_list = one_list->next;

    while(one_list->is_dummy == FALSE)
    {
        while(two_list->is_dummy == FALSE)
        {
            if(one_list->value > two_list->value)
            {
                stock = one_list->value;
                one_list->value = two_list->value;
                two_list->value = stock;
            }
            two_list = two_list->next;
        }
        one_list = one_list->next;
        two_list = one_list->next;
    }
}

void    swap_right_left(t_list *start_list, t_list *end_list)
{
    int stock = start_list->value;

    start_list->value = end_list->value;
    end_list->value = stock;
}

int     length_to_end(t_list *list)
{
    int i = 0;

    while(list->is_dummy != TRUE)
    {
        list = list->next;
        i++;
    }

    return (i);
}

int     length_to_start(t_list *list)
{
    int i = 0;

    while(list->is_dummy != TRUE)
    {
        list = list->prev;
        i++;
    }

    return (i);
}

int select_pivot(t_list *start, t_list *end)
{
    int i;

    i = length_to_start(end) - length_to_start(start);
    i /= 2;
    while(i)
    {
        start = start->next;
        i--;
    }
    return (start->value);

}

void    illegal_quick_sort_rec(t_list *list, t_list *start, t_list *end)
{
    int pivot = select_pivot(start, end);
    printf("pivot is %d\n", pivot);
    t_list  *left_list = start;
    t_list  *right_list = end;

    //while(is_sorted(list) == FALSE)
    while(1)
    {
        while(left_list->value < pivot)
            left_list = left_list->next;
        while(right_list->value > pivot)
            right_list = right_list->prev;
        
        if(length_to_start(left_list) >= length_to_start(right_list))
        {
            // printf("stop this section\n");
            illegal_stack_check(list);
            break;
        }
        swap_right_left(right_list, left_list);

        right_list = right_list->prev;        
        left_list = left_list->next;
    }

    if(length_to_start(left_list) >= 2)
        illegal_quick_sort_rec(list, left_list->next, end);
    if(length_to_end(right_list) >= 2)
        illegal_quick_sort_rec(list, start, right_list->prev);
}

void    illegal_quick_sort(t_list *a_dummy)
{
    illegal_quick_sort_rec(a_dummy, a_dummy->next, a_dummy->prev);
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

    // struct timespec begin, end;
    // clock_gettime(CLOCK_REALTIME, &begin);
    illegal_quick_sort(a_dummy);

    // clock_gettime(CLOCK_REALTIME, &end);
    // double summed = 0;
    // summed += (double)(end.tv_sec - begin.tv_sec);
    // summed += (double)(end.tv_nsec - begin.tv_nsec) / (1000 * 1000 * 1000);

    // printf("\nresult is %f\n", summed);

    stack_check(a_dummy, b_dummy);
}