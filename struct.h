/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:06:26 by gclement          #+#    #+#             */
/*   Updated: 2022/12/22 10:51:52 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_list;

typedef struct s_index
{
	int		index;
	int		nb;
	struct s_index *next;
}	t_index;

#endif