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

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_index	*stack_min;
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
	//
	//stack_min = create_stack_index(stack_a);
	//display(&stack_min);
	//while(check_is_order(stack_a) == 0)
	//{
		order_stack(&stack_a, &stack_b);
		//ft_printf("\n");
		//display_stack(&stack_a, 'a');
		//ft_printf("\n");
		//display_stack(&stack_b, 'b');
		//ft_printf("\n");
		//clear_stack(&stack_b, &stack_a);
		// ft_printf("------------ After Clear -----------\n");
		// display_stack(&stack_a, 'a');
		// ft_printf("\n");
		// display_stack(&stack_b, 'b');
		// ft_printf("\n");
	//}
	// ft_printf("\n");
	display_stack(&stack_a, 'a');
	display_stack(&stack_b, 'b');
	// ft_printf("size = %d\n", ft_lstsize(stack_a));
	return (free(stack_a), free(stack_b), free(arg_tab), 0);
}
