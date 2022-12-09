/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:15:24 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 17:14:38 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "struct.h"

void	display_stack(t_list *stack, char name);
t_list	*create_stack(int argc, char *argv[]);
void	ft_lstadd_back_stack(t_list **lst, t_list *new);
t_list	*ft_lstnew_stack(int content);

void	swap(t_list *stack);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list *stack);
void	reverse_rotate(t_list *stack);

#endif