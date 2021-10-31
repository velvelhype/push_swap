#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  "../libft/libft.h"
#include <time.h>
#include <sys/time.h>
#define	TRUE 1
#define FALSE 0
#define SORTED 1
#define CHUNK 0
#define UNKNOWN 2

typedef	struct	t_list
{
    int             is_dummy;
	int				value;
	int				sort_status;
	struct t_list	*next;
	struct t_list	*prev;
}   t_list;

void    create(t_list *head, t_list *dummy, int val);
void    b_dummy_set(t_list  *dummy);
void    append(t_list *list, t_list *dummy, int val);
void    set_sort_status(t_list *a_dummy, t_list *b_dummy);
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
void 	illegal_stack_check(t_list *a_dummy);
int     count_list(t_list *list);


void    finish_list(t_list  *list);

void    recursive_sort(t_list *a_dum, t_list *b_dum);
void    first_sort(t_list *a_dum, t_list *b_dum);