/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:50:17 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 20:59:07 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// #include<stdio.h>
// int main()
// {
//     printf("%d\n", ft_isdigit(0));
//     printf("%d\n", ft_isdigit('4'));
//     printf("%d\n", ft_isdigit('p'));
//     printf("%d\n", ft_isdigit(22));
//     printf("%d\n", ft_isdigit(-1));
//     return (0);
// }
