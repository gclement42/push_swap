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
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_index *get_good_node(t_list *stack)
{
	t_index	*stack_arg;
	t_index	*higher;
	t_index	*lower;

	stack_arg = create_stack_index(stack);
	higher = stack_arg;
	lower = stack_arg;
	while (lstsize(stack_arg) != 0 && stack_arg->next)
	{
		if (higher->index < stack_arg->index)
			higher = stack_arg;
		if (lower->index > stack_arg->index)
			lower = stack_arg;
		stack_arg = stack_arg->next;
	}
	if (ft_lstsize(stack) - higher->index > lower->index)
		return (lower);
	return (higher);
}

t_index  *create_stack_index(t_list *stack)
{
	int		count;
	t_index	*node;
	t_index	*lst;
	t_list 	*first;

	count = 0;
	first = stack;
	lst = NULL;
	node = newnode(&lst, count, stack);
	while (lstsize(lst) < 10 || ft_lstsize(stack) > 10)
	{
		if (lst == NULL && stack->content <= node->nb)
			node = newnode(&lst, count, stack);
		else if (stack->content <= node->nb && stack->content > lst->nb)
			node = newnode(&lst, count, stack);
		count++;
		if(stack->next == NULL)
		{
			stack = first;
			ft_lstadd_front_index(&lst, node);
			node = newnode(&lst, count, stack);
			count = 0;
		}
		else
		stack = stack->next;
	}
	return (lst);
}