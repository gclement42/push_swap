/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:59 by gclement          #+#    #+#             */
/*   Updated: 2023/01/03 17:52:51 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_order(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->next->content < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_is_order_rev(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->next->content > stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	delone(t_index **stack, t_index *node)
{
	t_index	*tmp;

	//display(stack);
	tmp = *stack;
	if (!*stack || !node)
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	if ((*stack)->nb == node->nb)
	{
		*stack = tmp->next;
		free(node);
		return ;
	}
	while (tmp->next->nb != node->nb && tmp)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	free (node);
	node = NULL;
}

void	rotate_min(t_index *index, t_list **stack_a, t_list **stack_b)
{
	while (index->index > 0)
	{
		if (index->index < ft_lstsize(*stack_a) / 2)
		{
			rotate(*stack_a, 'a');
			index->index--;
		}
		else
		{
			reverse_rotate(*stack_a, 'a');
			index->index++;
			if (index->index > ft_lstsize(*stack_a) - 1)
				index->index = 0;
		}
	}
	push(stack_a, stack_b, 'b');
	//display_stack(stack_b, 'b');
}

void	order_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;
	t_index	*stack_index;
	t_index	*node;

	if (!*stack_a)
		return ;
	while (ft_lstsize(*stack_a) >= 3)
	{
		stack_index = NULL;
		stack_index = create_stack_index(*stack_a, stack_index);
		//display(&stack_index);
		node = get_good_node(*stack_a, stack_index);
		rotate_min(node, stack_a, stack_b);
		delone(&stack_index, node);
		last_b = ft_lstlast(*stack_b);
		if (*stack_b && last_b
			&& (*stack_b)->content < last_b->content)
			rotate(*stack_b, 'b');
		if (*stack_b && (*stack_b)->next
			&& (*stack_b)->content < (*stack_b)->next->content)
			swap(*stack_b, 'b');
	}
}

void	clear_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;

	last_b = ft_lstlast(*stack_b);
	while (*stack_a != NULL)
	{
		while (check_is_order(*stack_b) == 0)
		{		
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content > (*stack_b)->next->content)
				swap(*stack_b, 'a');
			else if (*stack_b && last_b
				&& (*stack_b)->content > last_b->content)
				rotate(*stack_b, 'a');
			else
				push(stack_b, stack_a, 'b');
		}
		push(stack_a, stack_b, 'a');
	}
}
