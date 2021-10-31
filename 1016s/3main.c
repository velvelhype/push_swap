#include "push_swap.h"

void baka_sort(t_list   *a_dummy)
{
    t_list  *one_list;
    t_list  *two_list;
    int     stock;

    one_list = a_dummy;
    one_list = one_list->next;
    two_list = one_list->next;

    while (one_list->is_dummy == FALSE)
    {
        while (two_list->is_dummy == FALSE)
        {
            if (one_list->value > two_list->value)
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

int     select_pivot(t_list *start, t_list *end)
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

int     find_min(t_list *b)
{
    int     min;
    b = b->next;
    min = b->value;
    b = b->next;

    while(b->is_dummy == FALSE)
    {
        if(b->value < min)
            min = b->value;
        b = b->next;
    }
    return  min;
}

void    sort_rec_b(t_list *a, t_list *b)
{
    t_list  *end = b;
    end = end->prev;
    int     lists_number = count_list(b);
    int     min_value = find_min(b);
    int     pivot = lists_number / 2 + find_min(b);
    printf("pivot is %d\n", pivot);

    t_list  *cur;
    int     loop_count = 0;

    while(1)
    {
        cur = b->next;
        if(cur->value > pivot)
        {
            push(b,a);
            cur = b->next;
        }
        else
            rotate(b);
        loop_count++;

        if(loop_count == lists_number)
        {

            if(count_list(b) > 3)
            {
                sort_rec_b(a, b);
            }
            else
            {
                finish_list(b);

                lists_number = count_list(b);
                while(lists_number--)
                {
                    push(b,a);
                    rotate(a);
                }
                if((a->next)->sort_status == SORTED)
                    printf("no more chunk\n");
                else
                    {
                        push(a,b);
                        while((a->next)->sort_status == UNKNOWN)
                            push(a,b);
                        printf("go next rec\n");
                        stack_check(a,b);
                        read(1,NULL,1);
                        sort_rec_b(a,b);
                    }
            }
            break;
        }
    }    
}

void    init_stack_for_sort(t_list *a, t_list *b)
{
    t_list  *end = a;
    end = end->prev;
    int     lists_number = count_list(a);
    int     min_value = find_min(a);
    int     pivot = lists_number / 2 + min_value;
    t_list  *cur;
    int     loop_count = 0;


    while(1)
    {
        cur = a->next;
        if(cur->value < pivot)
        {
            push(a,b);
            cur = a->next;
        }
        else
            rotate(a);
        loop_count++;
        if(loop_count == lists_number)
        {
            printf("Enter to rec\n");
            (a->next)->sort_status = CHUNK;
            sort_rec_b(a, b);
            break;
        }
    }
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
    set_sort_status(a_dummy, b_dummy);
    // struct timespec begin, end;
    // clock_gettime(CLOCK_REALTIME, &begin);
    init_stack_for_sort(a_dummy, b_dummy);

    // clock_gettime(CLOCK_REALTIME, &end);
    // double summed = 0;
    // summed += (double)(end.tv_sec - begin.tv_sec);
    // summed += (double)(end.tv_nsec - begin.tv_nsec) / (1000 * 1000 * 1000);

    // printf("\nresult is %f\n", summed);

    printf("Sort end\n");
    stack_check(a_dummy, b_dummy);
}