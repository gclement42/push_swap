/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:59 by gclement          #+#    #+#             */
/*   Updated: 2022/12/22 10:18:15 by gclement         ###   ########.fr       */
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

int	search_max(t_list *stack)
{
	int		count;
	int		max_pos;
	t_list	*max;

	count = 0;
	max = stack;
	max_pos = count;
	if (stack == NULL)
		return (0);
	while (stack)
	{

		if (stack->content > max->content)
		{
			max = stack;
			max_pos = count;
		}
		count++;
		stack = stack->next;
	}
	return (max_pos);
}

int	search_min(t_list *stack)
{
	int		count;
	int		min_pos;
	t_list	*min;

	count = 0;
	min = stack;
	min_pos = count;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->content < min->content)
		{
			min = stack;
			min_pos = count;
		}
		count++;
		stack = stack->next;
	}
	return (min_pos);
}

void	order_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;

	if (!*stack_a)
		return ;
	last_a = ft_lstlast(*stack_a);
	while (check_is_order(*stack_a) != 1)
	{
		// display_stack(stack_a, 'a');
		// display_stack(stack_b, 'b');
		if ((*stack_a)->content > last_a->content)
			reverse_rotate(*stack_a, 'a');
		if ((*stack_b && (*stack_b)->next)
			&& ((*stack_a)->content > (*stack_a)->next->content
				&& (*stack_b)->content < (*stack_b)->next->content))
			swap_all(*stack_a, *stack_b);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap(*stack_a, 'a');
		push(stack_a, stack_b, 'b');
		if (ft_lstsize(*stack_b) == 3)
			clear_stack(stack_b, stack_a);
	}
}

void	clear_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;

	last_b = ft_lstlast(*stack_b);
	while (*stack_a != NULL)
	{
		display_stack(stack_a, 'a');
		display_stack(stack_b, 'b');
		if ((*stack_a && (*stack_a)->next)
			&& (*stack_a)->next->content > (*stack_a)->content)
			swap(*stack_a, 'b');
		ft_printf("ok");
		while (search_max(*stack_a) > 0)
		{
			if (search_max(*stack_a) < ft_lstsize(*stack_a) / 2)
				rotate(*stack_a, 'b');
			else
				reverse_rotate(*stack_a, 'b');
		}
		push(stack_a, stack_b, 'a');
	}
}
