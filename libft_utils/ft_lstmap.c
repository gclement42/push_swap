/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:55 by gclement          #+#    #+#             */
/*   Updated: 2022/12/08 10:48:09 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new;
	t_stack	*tab;
	char	*str;

	if (!(*f) || !(*del))
		return (NULL);
	tab = NULL;
	while ((lst) != NULL)
	{
		str = (f)(lst->content);
		new = ft_lstnew(str);
		if (!new)
		{
			del(str);
			ft_lstclear(&tab, del);
			return (NULL);
		}
		ft_lstadd_back(&tab, new);
		lst = lst->next;
	}
	return (tab);
}
