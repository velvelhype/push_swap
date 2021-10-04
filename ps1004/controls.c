#include "push_swap.h"

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

void    swap(t_list *list)
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

void    push(t_list *a_dummy, t_list *b_dummy)
{
    t_list *a1 = a_dummy->next;
    t_list *a2 = a1->next;
    t_list *b1 = b_dummy->next;
    t_list *b2 = b1->next;

    cut (a_dummy, a2);
    insert  (b_dummy, a1, b1);
}

void    rotate(t_list *dum)
{
    t_list *cul = dum->next;
    int init = cul->value;
    int save;

    cul = dum->prev;
    save = cul->value; 
    cul->value = init;
    cul = cul->prev;

    while(!cul->dum_check)
    {
        init = cul->value;
        cul->value = save;
        save = init;
        cul = cul->prev;
    }
}

void   r_rotate(t_list *dum)
{
    t_list *cul = dum->prev;
    int init = cul->value;
    int save;

    cul = dum->next;
    save = cul->value; 
    cul->value = init;
    cul = cul->next;

    while(!cul->dum_check)
    {
        init = cul->value;
        cul->value = save;
        save = init;
        cul = cul->next;
    }
}