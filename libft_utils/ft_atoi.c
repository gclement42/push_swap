/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:36:31 by gclement          #+#    #+#             */
/*   Updated: 2022/11/18 11:58:27 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = check_isspace(str);
	nb = 0;
	sign = 1;
	if ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb != ((nb * 10) + (str[i] - '0')) / 10)
			return ((sign + 1) / -2);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
