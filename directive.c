/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:23 by gclement          #+#    #+#             */
/*   Updated: 2022/12/15 11:17:06 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Intervertit les 2 premiers elements au sommet de la pile*/
void	swap(t_list *stack, char name)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	if (name != 'A')
		ft_printf("s%c\n", name);
}

/* : Prend le premier élément au sommet de A et le met sur B*/
void	push(t_list **stack_a, t_list **stack_b, char name)
{
	t_list	*new;
	t_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	new = ft_lstnew_stack((*stack_a)->content);
	ft_lstadd_front(stack_b, new);
	if ((*stack_a)->next == NULL)
	{
		free(*stack_a);
		*stack_a = NULL;
		return ;
	}	
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->before = NULL;
	free(tmp);
	ft_printf("p%c\n", name);
}
/* Décale d’une position vers le haut tous les élements de la pile*/

void	rotate(t_list *stack, char name)
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
	if (name != 'A')
		ft_printf("r%c\n", name);
}
/* Décale d’une position vers le bas tous les élements de la pile */

void	reverse_rotate(t_list *stack, char name)
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
	if (name != 'A')
		ft_printf("rr%c\n", name);
}
