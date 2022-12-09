/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:14 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 14:54:32 by gclement         ###   ########.fr       */
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
			exit(ft_printf("%s", FAILURE));
		lst = lst->next;
	}
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
		ft_lstadd_back_stack(&stack_a, lst);
		i++;
	}
	return (stack_a);
}

void	display_stack(t_list *stack, char name)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
	ft_printf("_\n%c\n", name);
}
