/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:06:16 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 21:29:53 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (0);
	return (1);
}
// #include<stdio.h>
// int main()
// {
//     printf("%d\n", ft_isascii('%'));
//     printf("%d\n", ft_isascii('0'));
//     printf("%d\n", ft_isascii(128));
//     printf("%d\n", ft_isascii(144));
//     printf("%d\n", ft_isascii(1));
//     return (0);
// }
