#include "push_swap.h"


void	ft_lstadd_front_index(t_index **lst, t_index *new)
{
	new->next = *lst;
	*lst = new;
}

t_index	*newnode(t_index **stack, int index, t_list *node)
{
    t_index	*new;

    new = malloc(sizeof(t_index));
    if (!new)
        return (NULL);
    new->next = NULL;
	new->index = index;
	new->nb = node->content;
	return (new);
}

int lstsize(t_index *stack)
{
	int count;

	count = 0;
	while (stack->next)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void dellast(t_index **stack)
{
	while ((*stack)->next)
		*stack = (*stack)->next;
	free((*stack)->next);
	(*stack)->next = NULL;
}

t_index  *create_stack_index(t_list *stack)
{
	int		count;
	t_index	*node;
	t_index	*lst;
	int		min;

	count = 0;
	min = stack->content;
	lst = NULL;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			node = newnode(&lst, count, stack);
			//ft_printf("before node->next = %p\n", node->next);
			ft_lstadd_front_index(&lst, node);
			//ft_printf("after node->next = %p\n", node->next);
			//if (lstsize(lst) >= 10)
			//	dellast(&lst);
		}
		count++;
		stack = stack->next;
	}
	return (lst);
}