/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:49 by gclement          #+#    #+#             */
/*   Updated: 2022/12/22 16:03:48 by gclement         ###   ########.fr       */
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

int	check_is_order_reverse(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->next->content > stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arg_tab;
	int		i;

	i = 0;
	arg_tab = NULL;
	stack_b = NULL;
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
	i = 0;
	while (check_is_order(stack_a) == 0)
	{
		order_stack(&stack_a, &stack_b);
		// ft_printf("\n");
		// display_stack(&stack_a, 'a');
		// ft_printf("\n");
		// display_stack(&stack_b, 'b');
		// ft_printf("\n");
		clear_stack(&stack_b, &stack_a);
		// ft_printf("------------ After Clear -----------\n");
		// display_stack(&stack_a, 'a');
		// ft_printf("\n");
		// display_stack(&stack_b, 'b');
		// ft_printf("\n");
	}
	// ft_printf("\n");
	// display_stack(&stack_a, 'a');
	// display_stack(&stack_b, 'b');
	// ft_printf("size = %d\n", ft_lstsize(stack_a));
	return (free(stack_a), free(stack_b), free(arg_tab), 0);
}
