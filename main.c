/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:21:49 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 17:17:24 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		exit(ft_printf("%s", FAILURE));
	if (argc == 2)
	{
		arg_tab = ft_split(argv[1], ' ');
		while (arg_tab[i])
			i++;
		stack_a = create_stack(i, arg_tab);
	}
	else
		stack_a = create_stack(argc - 1, argv + 1);
	display_stack(stack_a, 'a');
}
