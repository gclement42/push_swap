/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:49 by gclement          #+#    #+#             */
/*   Updated: 2023/01/05 13:31:40 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_list **stack, char name)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		ft_printf("%d\n", (tmp)->content);
		tmp = (tmp)->next;
	}
	ft_printf("_\n%c\n", name);
}

void	display(t_index **stack)
{
	t_index	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("content = %d\nindex = %d\n", (tmp)->nb, (tmp)->index);
		tmp = (tmp)->next;
	}
}

t_index	*get_max(t_list *stack)
{
	t_list	*tmp;
	t_index	*max;
	int		i;

	i = 0;
	tmp = stack;
	max = newnode(i, stack);
	while (tmp)
	{
		if (tmp->content > max->nb)
		{
			max->nb = tmp->content;
			max->index = i;
		}
		tmp = tmp->next;
		i++;
	}	
	return (max);
}

void	push_swap(t_list *stack_a, t_list *stack_b)
{
	t_index	*node;

	node = NULL;
	while (check_is_order(stack_a) == 0)
	{
		if (ft_lstsize(stack_a) > 5)
			order_stack(&stack_a, &stack_b);
		if ((ft_lstsize(stack_a) <= 3 && stack_b == NULL)
			|| check_is_order(stack_a) == 0)
			order(&stack_b, &stack_a);
		while (stack_b != NULL)
		{
			while (check_is_order(stack_a) == 0)
				order(&stack_b, &stack_a);
			node = get_max(stack_b);
			rotate_min(node, &stack_b, &stack_a, 'b');
		}
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arg_tab;

	arg_tab = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1)
		exit(ft_printf("Error\n"));
	if (argc == 2)
	{
		arg_tab = ft_split(argv[1], ' ');
		while (arg_tab[i])
			i++;
		stack_a = create_stack(i, arg_tab);
	}
	else
		stack_a = create_stack(argc - 1, argv + 1);
	push_swap(stack_a, stack_b);
	return (free(arg_tab), 0);
}
