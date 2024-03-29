/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:15:24 by gclement          #+#    #+#             */
/*   Updated: 2023/01/05 13:23:16 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "struct.h"

t_list	*create_stack(int argc, char *argv[]);
void	ft_lstadd_back_stack(t_list **lst, t_list *new);
t_list	*ft_lstnew_stack(int content);
void	display_stack(t_list **stack, char name);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	swap(t_list *stack, char name);
void	push(t_list **stack_a, t_list **stack_b, char name);
void	rotate(t_list *stack, char name);
void	reverse_rotate(t_list *stack, char name);

void	swap_all(t_list *stack_a, t_list *stack_b);
void	rotate_all(t_list *stack_a, t_list *stack_b);
void	rotate_reverse_all(t_list *stack_a, t_list *stack_b);

int		check_is_order(t_list *stack);
void	order_stack(t_list **stack_a, t_list **stack_b);
int		search_max(t_list *stack);
void	rotate_min(t_index *index, t_list **stack_a, t_list **stack_b, char n);

t_index	*create_stack_index(t_list *stack, t_index *lst, t_index *max,\
int size);
t_index	*get_good_node(t_list *stack_a, t_index *stack_index);
void	order(t_list **stack_a, t_list **stack_b);
t_index	*get_max(t_list *stack);

int		main(int argc, char *argv[]);

void	display(t_index **stack);
void	delone(t_index **stack, t_index *node);

t_index	*newnode(int index, t_list *node);
void 	check_error(void);

int		ft_atoi(const char *str);

#endif