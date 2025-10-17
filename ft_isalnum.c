/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:57:34 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 21:05:25 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 0 && c <= 9) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}
// #include<stdio.h>
// int main()
// {
//     printf("%d\n", ft_isalnum('4'));
//     printf("%d\n", ft_isalnum('@'));
//     printf("%d\n", ft_isalnum(0));
//     printf("%d\n",ft_isalnum('Z'));
//     printf("%d\n",ft_isalnum('a'));
//     return (0);
// }
