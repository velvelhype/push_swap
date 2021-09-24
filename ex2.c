#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  "../libft/libft.h"

typedef	struct	s_list
{
    int             dum_check;
	long			value;
	struct t_list	*next;
	struct t_list	*prev;
}   t_list;

void    create(t_list *head, t_list *dummy, int val)
{
    head->value = val;
    head->next = dummy;
    head->prev = dummy;
    dummy->dum_check = 1;
    dummy->next = head;
    dummy->prev = head;
}

void    b_dummy_set(t_list  *dummy)
{
    dummy->dum_check = 1;
    dummy->next = dummy;
    dummy->prev = dummy;
}

void    append(t_list *list, t_list *dummy, int val)
{
    t_list  *new = malloc(sizeof(t_list));
    t_list  *tail;

    tail = dummy->prev;
    new->value = val;
    new->next = dummy;
    new->prev = tail;
    dummy->prev = new;
    tail->next = new;
}

void    sa(t_list *list)
{
    t_list *next;
    long    esc;

    next = list->next;
    esc = list->value;
    list->value = next->value;
    next->value = esc;
}

void    cut(t_list *a, t_list *c)
{
    a->next = c;
    c->prev = a;
}

void    insert(t_list *a, t_list *b, t_list *c)
{
    a->next = b;
    c->prev = b;
    b->next = c;
    b->prev = a;
}

void    pb(t_list *a_dummy, t_list *b_dummy)
{
    t_list *a1 = a_dummy->next;
    t_list *a2 = a1->next;
    t_list *b1 = b_dummy->next;
    t_list *b2 = b1->next;

    cut (a_dummy, a2);
    insert  (b_dummy, a1, b1);
}

t_list*    ra(t_list *dum)
{
    t_list *head;

    head = dum->next;
    dum->value = head->value;
    dum->dum_check = 0;
    head->dum_check = 1;
    return(head);
}

t_list*    rra(t_list *dum)
{
    t_list *tail;

    tail = dum->prev;
    dum->value = tail->value;
    dum->dum_check = 0;
    tail->dum_check = 1;
    return(tail);
}

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

t_list*    three_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    t_list  *three;

    one = dum->next;
    two = one->next;
    three = two->next;

    //printf("%d %d %d\n", one->value, two->value, three->value);

    if(is_sorted(dum) == 1)
        return dum;

    if(one->value > two->value)
    {
        if(two->value > three->value)
            {
                sa(one);
                dum = rra(dum);
            }
        else if (one->value < three->value)
            sa(one);
        else
            dum = ra(dum);
    }
    else if (one->value < three->value)
        {
            sa(one);
            dum = ra(dum);
        }
    else
        dum = rra(dum);
    
    //printf("%d %d %d\n", one->value, two->value, three->value);

    return(dum);
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


    if(argc == 4)
        a_dummy = three_sort(a_dummy);
    printf("is sorted %d\n", is_sorted(a_dummy));

    printf("gonna check the a_stacks\n");
    a_dummy = a_dummy->next;
    while(a_dummy->dum_check != 1)
    {
        printf("%d\n",a_dummy->value);
        a_dummy = a_dummy->next;
    }
    printf("gonna check the b_stacks\n");
    while(b_dummy->dum_check != 1)
    {
        printf("%d\n", b_dummy->value);
        b_dummy = b_dummy->next;
    }
}