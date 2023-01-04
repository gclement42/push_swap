/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:09:26 by gclement          #+#    #+#             */
/*   Updated: 2023/01/03 17:00:49 by gclement         ###   ########.fr       */
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
	//display(&stack_index);
	if (!stack_index)
		return (NULL);
	while (lstsize(stack_index) != 0 && stack_index)
	{
		if (stack_index->index > ft_lstsize(stack) / 2)
			count++;
		if (higher->index < stack_index->index)
			higher = stack_index;
		if (lower->index > stack_index->index)
			lower = stack_index;
		stack_index = stack_index->next;
	}
	if (count > lstsize(stack_index) / 2)
		return (higher);
	if (ft_lstsize(stack) - higher->index > lower->index || lower->index == 0)
		return (lower);
	return (higher);
}

// t_index	*get_good_node_2(t_list *stack_a, t_list *stack_b, t_index *stack_index)
// {
// 	int		i;
// 	t_index	*higher;
// 	t_index	*lower;

// 	i = 0;
// 	higher = stack_index;
// 	lower = stack_index;
// 	if (!stack_b)
// 	{
// 		while (lstsize(stack_index) / 2 + 2 > i++)
// 			stack_index = stack_index->next;
// 		return (stack_index);
// 	}
// 	while (stack_index)
// 	{
// 		if (stack_index->nb > stack_b->content)
// 			higher = stack_index;
// 		if (stack_index->nb < stack_b->content && lower == NULL)
// 			lower = stack_index;
// 		stack_index = stack_index->next;
// 	}
// 	if (lower && higher && ft_lstsize(stack_a) - higher->index > lower->index)
// 		return (lower);
// 	return (higher);
// }

t_index	*get_max(t_list *stack)
{
	t_list	*tmp;
	t_index	*max;
	int		i;

	i = 0;
	tmp = stack;
	max = newnode(i, stack);
	while (tmp)
	{
		if (tmp->content > max->nb)
		{
			max->nb = tmp->content;
			max->index = i;
		}
		tmp = tmp->next;
		i++;
	}	
	return (max);
}

t_index	*create_stack_index(t_list *stack, t_index *lst)
{
	int		count;
	t_index	*node;
	int		stack_size;
	t_list	*first;
	t_index	*max;

	count = 0;
	first = stack;
	stack_size = ft_lstsize(stack);
	node = newnode(count, stack);
	max = get_max(stack);
	while (lstsize(lst) < 10 && lstsize(lst) < stack_size && stack)
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
