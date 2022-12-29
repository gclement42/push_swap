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
/*
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
			ft_printf("%d\n", index);
			index++;
			if (index == ft_lstsize(*stack_a))
				index = 0;
		}
	}
	push(stack_a, stack_b, 'b');
	if (*stack_b && (*stack_b)->next
		&& (*stack_b)->content < (*stack_b)->next->content)
		swap(*stack_b, 'b');
}

void	order_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;
	t_index	*stack_index;
	int		count;

	count = 0;
	if (!*stack_a)
		return ;
	last_a = ft_lstlast(*stack_a);
	while (check_is_order(*stack_a) != 1 && index != NULL)
	{

		stack_index = create_stack_index(*stack_a);
		if (index->min < ft_lstsize(*stack_a) / 2
			&& index->previous_min > 0 && index->previous_min < ft_lstsize(*stack_a) && index->min > index->previous_min)
			rotate_min(index->previous_min, stack_a, stack_b);
		else if (index->min > ft_lstsize(*stack_a) / 2
			&& (index->previous_min > 0 && index->previous_min < ft_lstsize(*stack_a)) && index->min < index->previous_min)
			rotate_min(index->previous_min, stack_a, stack_b);
		else
			rotate_min(index->min, stack_a, stack_b);
		index = search_index(*stack_a);
		//if (count < 10)
		// 	display_stack(stack_b, 'b');
		// count++;
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
	}
}
*/