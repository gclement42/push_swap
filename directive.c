/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:23 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 14:30:29 by gclement         ###   ########.fr       */
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

/* : Prend le premier élément au sommet de B et le met sur A & vice-versa*/
void	push(t_list *stack_a, t_list *stack_b)
{
	t_list	*new;

	new = ft_lstnew_stack(stack_a->content);
	ft_lstadd_back_stack(&stack_b, new);
}