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

void    create(t_list *head, t_list *dummy, int val);
void    b_dummy_set(t_list  *dummy);
void    append(t_list *list, t_list *dummy, int val);
void    cut(t_list *a, t_list *c);
void    insert(t_list *a, t_list *b, t_list *c);
void    push(t_list *a_dummy, t_list *b_dummy);
void    swap(t_list *list);
void    rotate(t_list *dum);
void    r_rotate(t_list *dum);

int     is_sorted(t_list *a);
void    two_sort(t_list *dum);
void    three_sort(t_list *dum);
void    stack_check(t_list *a_dummy, t_list *b_dummy);
int     count_list(t_list *list);

void    recursive_sort(t_list *a_dum, t_list *b_dum);
void    first_sort(t_list *a_dum, t_list *b_dum);