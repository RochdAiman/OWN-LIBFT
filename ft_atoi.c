/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:04:14 by arochd            #+#    #+#             */
/*   Updated: 2025/10/18 11:02:38 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"e

static	int	over_flow(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	of;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		of = result * 10 + (str[i] - '0');
		if (of < result)
			return (over_flow(sign));
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)result * sign);
}	
