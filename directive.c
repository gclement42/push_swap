/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:23 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 17:16:32 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Intervertit les 2 premiers elements au sommet de la pile*/
void	swap(t_list *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("\nhead = %d\n", stack->content);
	ft_printf("head->before = %d\n", stack->next->content);
}

/* : Prend le premier élément au sommet de A et le met sur B*/
void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;
	t_list	*tmp;

	if (!stack_a)
		return ;
	new = ft_lstnew_stack((*stack_a)->content);
	ft_lstadd_back_stack(stack_b, new);
	tmp = (*stack_a)->next;
	free(*stack_a);
	*stack_a = tmp;
	(*stack_a)->before = NULL;
}

void	rotate(t_list *stack)
{
	int	tmp;

	if (!stack)
		return ;
	while (stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack = stack->next;
		stack->content = tmp;
	}
}

void	reverse_rotate(t_list *stack)
{
	int	tmp;

	if (!stack)
		return ;
	while (stack->next)
		stack = stack->next;
	while (stack->before)
	{
		tmp = stack->content;
		stack->content = stack->before->content;
		stack = stack->before;
		stack->content = tmp;
	}
}
