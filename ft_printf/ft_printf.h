/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:10:35 by gclement          #+#    #+#             */
/*   Updated: 2022/11/22 13:15:55 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

int		ft_putnbr_base_and_count(va_list args, int type);
int		ft_printf(const char *format, ...);
int		ft_put_unsigned_int(unsigned int nbr, int fd);
int		ft_putstr_and_count(char *s, int fd);
int		ft_putnbr_and_count(int n, int fd);

#endif