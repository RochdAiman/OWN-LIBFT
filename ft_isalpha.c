/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:22:56 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 20:41:28 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}
// #include<stdio.h>
// int main()
// {
//     printf("%d\n", ft_isalpha('A'));
//     printf("%d\n", ft_isalpha('a'));
//     printf("%d\n", ft_isalpha('0'));
//     printf("%d\n", ft_isalpha(' '));
//     printf("%d\n", ft_isalpha('&'));
//     printf("%d\n", ft_isalpha());
//     return (0);
// }
