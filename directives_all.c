/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directives_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:21:54 by gclement          #+#    #+#             */
/*   Updated: 2022/12/16 10:47:44 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_all(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 'A');
	swap(stack_b, 'A');
	ft_printf("ss\n");
}

void	rotate_all(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a, 'A');
	rotate(stack_b, 'A');
	ft_printf("rr\n");
}

void	rotate_reverse_all(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a, 'A');
	reverse_rotate(stack_b, 'A');
	ft_printf("rrr\n");
}

