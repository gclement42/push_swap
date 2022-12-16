/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:59 by gclement          #+#    #+#             */
/*   Updated: 2022/12/16 11:09:00 by gclement         ###   ########.fr       */
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

static void	order_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;
	t_list	*last_b;

	if (!*stack_a)
		return ;
	last_a = ft_lstlast(*stack_a);
	while (check_is_order(*stack_a) != 1)
	{
		last_b = ft_lstlast(*stack_b);
		if ((*stack_b)
			&& ((*stack_a)->content > last_a->content
				&& (*stack_b)->content > last_b->content))
				{
					rotate_reverse_all(*stack_a, *stack_b);
					ft_printf("---------------------------------\n");
				}
		else if ((*stack_a)->content > last_a->content)
			reverse_rotate(*stack_a, 'a');
		if ((*stack_b && (*stack_b)->next)
			&& ((*stack_a)->content > (*stack_a)->next->content
				&& (*stack_b)->content > (*stack_b)->next->content))
			swap_all(*stack_a, *stack_b);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap(*stack_a, 'a');
		else if (check_is_order(*stack_a) == 0)
			push(stack_a, stack_b, 'b');
	}
	// if (check_is_order(*stack_b) == 0 && (*stack_b)->next)
	// 	order_stack(stack_b, stack_a);
}

void	clear_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;

	last_a = ft_lstlast(*stack_a);
	while (*stack_a != NULL)
	{
		push(stack_a, stack_b, 'b');
		if (check_is_order(*stack_b) == 0)
		{
			if ((*stack_b)->content > last_a->content)
				reverse_rotate(*stack_a, 'a');
			if ((*stack_b)->content > (*stack_b)->next->content)
				swap(*stack_a, 'a');
		}
		order_stack(stack_a, stack_b);
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	while (check_is_order(*stack_a) == 0)
	{
		order_stack(stack_a, stack_b);
		clear_stack(stack_b, stack_a);
	}
}
