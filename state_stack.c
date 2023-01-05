/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:09:26 by gclement          #+#    #+#             */
/*   Updated: 2023/01/05 12:49:44 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_index(t_index **lst, t_index *new)
{
	new->next = *lst;
	*lst = new;
}

t_index	*newnode(int index, t_list *node)
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

int	lstsize(t_index *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_index	*get_good_node(t_list *stack, t_index *stack_index)
{
	t_index	*higher;
	t_index	*lower;
	int		count;

	higher = stack_index;
	lower = stack_index;
	count = 0;
	if (!stack_index)
		return (NULL);
	while (lstsize(stack_index) != 0 && stack_index)
	{
		if (higher->index < stack_index->index)
			higher = stack_index;
		if (lower->index > stack_index->index)
			lower = stack_index;
		stack_index = stack_index->next;
	}
	if (ft_lstsize(stack) - higher->index > lower->index || lower->index == 0)
		return (lower);
	return (higher);
}

t_index	*create_stack_index(t_list *stack, t_index *lst, t_index *max, int size)
{
	int		count;
	t_index	*node;
	t_list	*first;

	count = 0;
	first = stack;
	node = newnode(count, stack);
	while (lstsize(lst) < 15 && lstsize(lst) < size && stack)
	{
		if (lst == NULL && stack->content <= node->nb)
			node = newnode(count, stack);
		else if (stack->content <= node->nb && stack->content > lst->nb)
			node = newnode(count, stack);
		count++;
		if (stack->next == NULL && (lst == NULL || node->nb != lst->nb))
		{
			stack = first;
			ft_lstadd_front_index(&lst, node);
			count = 0;
			node = max;
		}
		else
		stack = stack->next;
	}
	return (lst);
}
