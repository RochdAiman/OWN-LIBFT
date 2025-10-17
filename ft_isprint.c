/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:30:20 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 21:35:09 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 33 && c <= 126)
		return (0);
	return (1);
}
// #include<stdio.h>
// int main()
// {
//     printf("%d\n", ft_isprint(126));
//     printf("%d\n", ft_isprint(32));
//     printf("%d\n", ft_isprint(128));
//     printf("%d\n", ft_isprint(0));
//     printf("%d\n", ft_isprint(77));
//     return (0);
// }
