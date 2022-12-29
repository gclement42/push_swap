/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:59 by gclement          #+#    #+#             */
/*   Updated: 2022/12/22 16:06:06 by gclement         ###   ########.fr       */
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

void	rotate_min(int index, t_list **stack_a, t_list **stack_b)
{
	while (index > 0)
	{
		if (index < ft_lstsize(*stack_a) / 2)
		{
			rotate(*stack_a, 'b');
			index--;
		}
		else
		{
			reverse_rotate(*stack_a, 'b');
			if (index > ft_lstsize(*stack_a))
				break ;
			index++;
			if (index == ft_lstsize(*stack_a))
				index = 0;
		}
	}
}

void	order_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;
	t_index	*stack_index;
	int		count;

	count = 0;
	if (!*stack_a)
		return ;
	last_b = ft_lstlast(*stack_b);
	while (check_is_order(*stack_a) != 1)
	{
		stack_index = get_good_node(*stack_a);
		ft_printf("index = nb : %d, index : %d\n", stack_index->nb, stack_index->index);
		rotate_min(stack_index->index, stack_a, stack_b);
		push(stack_a, stack_b, 'b');
		while (check_is_order_rev(*stack_b) == 0)
		{
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content < (*stack_b)->next->content)
				swap(*stack_b, 'b');
			else if (*stack_b && last_b
				&& (*stack_b)->content < last_b->content)
				rotate(*stack_b, 'b');
			else
				push(stack_b, stack_a, 'a');
		}
		free(stack_index);
	}
}

void	clear_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;

	last_b = ft_lstlast(*stack_b);
	while (*stack_a != NULL)
	{
		// display_stack(stack_a, 'a');
		// display_stack(stack_b, 'b');
		push(stack_a, stack_b, 'a');
		while (check_is_order(*stack_b) == 0)
		{
			if (*stack_b && last_b
				&& (*stack_b)->content > last_b->content)
				rotate(*stack_b, 'b');
			else if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content > (*stack_b)->next->content)
				swap(*stack_b, 'b');
			else
				push(stack_b, stack_a, 'b');
		}

	}
}
