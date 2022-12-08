/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:14 by gclement          #+#    #+#             */
/*   Updated: 2022/12/08 10:53:27 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	int		i;
	t_stack	**stack_a;
	t_stack	*lst;

	i = 1;
	stack_a = &lst;
	while (i < argc)
	{	
		lst = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, lst);
		lst = lst->next;
		i++;
	}
	// while (lst != NULL)
	// {
	// 	printf("%s\n", lst->content);
	// 	lst = lst->next;
	// }
}
