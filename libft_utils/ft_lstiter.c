/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:34:13 by gclement          #+#    #+#             */
/*   Updated: 2022/12/08 10:47:42 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	t_stack	*tmp;

	if (!lst || !f)
		return ;
	while ((lst) != NULL)
	{
		tmp = lst->next;
		f(lst->content);
		lst = tmp;
		ft_printf("%s\n", lst->content);
	}
}
