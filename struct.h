/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:06:26 by gclement          #+#    #+#             */
/*   Updated: 2022/12/09 17:19:07 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define FAILURE "Error\n"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_list;

#endif