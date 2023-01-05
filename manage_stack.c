/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:14 by gclement          #+#    #+#             */
/*   Updated: 2023/01/04 15:35:22 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstlast_stack(t_list *lst, int content)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		if (content == lst->content)
			exit(ft_printf("%s", "Error\n"));
		lst = lst->next;
	}
	if (content == lst->content)
		exit(ft_printf("%s", "Error\n"));
	return (lst);
}

t_list	*ft_lstnew_stack(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->before = NULL;
	return (new);
}

void	ft_lstadd_back_stack(t_list **lst, t_list *new)
{
	t_list	*head;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = ft_lstlast_stack(*lst, new->content);
	head->next = new;
	new->before = head;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	new->before = NULL;
	if (*lst != NULL)
		(*lst)->before = new;
	*lst = new;
}

t_list	*create_stack(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*lst;

	i = 0;
	stack_a = NULL;
	while (i < argc)
	{	
		lst = ft_lstnew_stack(ft_atoi(argv[i]));
		if ((long) ft_atoi(argv[i]) < -2147483647)
			exit(ft_printf("Error\n"));
		ft_lstadd_back_stack(&stack_a, lst);
		i++;
	}
	return (stack_a);
}
