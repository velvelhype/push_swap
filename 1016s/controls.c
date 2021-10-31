#include "push_swap.h"

void    create(t_list *head, t_list *dummy, int val)
{
    head->value = val;
    head->next = dummy;
    head->prev = dummy;
    dummy->is_dummy = TRUE;
    dummy->next = head;
    dummy->prev = head;
}

void    b_dummy_set(t_list  *dummy)
{
    dummy->is_dummy = TRUE;
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

void    set_status(t_list   *list)
{
    t_list  *cur = list;

    cur->sort_status = UNKNOWN;
    cur = cur->next;
    while(cur != list)
    {
        cur->sort_status = UNKNOWN;
        cur = cur->next;
    }
}

void    set_sort_status(t_list *a, t_list *b)
{
    set_status(a);
    set_status(b);
}

void    swap(t_list *list)
{
    t_list *next;
    long    esc;

    next = list->next;

    esc = list->value;
    list->value = next->value;
    next->value = esc;

    esc = list->sort_status;
    list->sort_status = next->sort_status;
    next->sort_status = esc;
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
    t_list *cur = dum->next;
    int init = cur->value;
    int init_save;
    int status = cur->sort_status;
    int status_save;

    cur = dum->prev;

    init_save = cur->value; 
    status_save = cur->sort_status;

    cur->value = init;
    cur->sort_status = status;

    cur = cur->prev;

    while(cur->is_dummy == FALSE)
    {
        init = cur->value;
        status = cur->sort_status;
    
        cur->value = init_save;
        cur->sort_status = status_save;
    
        init_save = init;
        status_save = status;
    
        cur = cur->prev;
    }
}

void   r_rotate(t_list *dum)
{
    t_list *cur = dum->prev;
    int init = cur->value;
    int save;

    int init_status = cur->sort_status;
    int save_status;

    cur = dum->next;

    save = cur->value; 
    save_status = cur->sort_status;
    cur->value = init;
    cur->sort_status = init_status;

    cur = cur->next;

    while(cur->is_dummy == FALSE)
    {
        init = cur->value;
        init_status = cur->sort_status;
        cur->value = save;
        cur->sort_status = save_status;
        save = init;
        save_status = init_status;    
        cur = cur->next;
    }
}
