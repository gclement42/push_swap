/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:24:40 by gclement          #+#    #+#             */
/*   Updated: 2022/12/08 11:00:12 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../push_swap.h"

// typedef struct s_stack
// {
// 	int				content;
// 	struct s_stack	*next;
// 	struct s_stack	*before;
// }	t_stack;

t_stack			*ft_lstnew(int content);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
int				ft_lstsize(t_stack *lst);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			ft_lstdelone(t_stack *lst, void (*del)(void*));
void			ft_lstclear(t_stack **lst, void (*del)(void*));
void			ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack			*ft_lstmap(t_stack *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_atoi(const char *str);

#endif