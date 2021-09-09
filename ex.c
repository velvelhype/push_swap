#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  "../libft/libft.h"

typedef	struct	s_list
{
	long			value;
	struct t_list	*next;
	struct t_list	*prev;
}				t_list;

t_list  *append()
{
    t_list *new_list;
    new_list = malloc(sizeof(t_list));
    return  new_list;
};

void set_list(t_list *a_stack, char **argv)
{
    ++argv;
    while(argv)
    {
        a_stack->value = ft_atoi(*argv);
        argv++;
        printf("list has %ld\n", a_stack->value);
        if(argv)
        {
            a_stack->next = append();
            a_stack->prev = a_stack;
            a_stack = a_stack->next;
            printf("prev is %ld\n", a_stack->prev->value);
        }
    }
    
};

int main(int argc, char **argv)
{
   t_list a_stack;

    if(argc != 1)
    {
        //printf("%d\n", ft_atoi(*argv));
        set_list(&a_stack, argv);
        argv++;
    }
    //make_list();
    
}