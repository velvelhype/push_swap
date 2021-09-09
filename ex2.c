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

void    pb()
{
    
}

int main(int argc, char **argv)
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

    sa(a_stack);

    printf("gonna check the stacks\n");
    while(a_stack->dum_check != 1)
    {
        printf("%d\n",a_stack->value);
        a_stack = a_stack->next;
    }
}