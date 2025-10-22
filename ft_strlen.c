/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:55:56 by arochd            #+#    #+#             */
/*   Updated: 2025/10/17 15:59:59 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
// #include<stdio.h>
// int main()
// {

//     printf("the len is -> %zu\n", ft_strlen("NAPOLI"));
//     printf("the len is -> %zu\n", ft_strlen(""));
//     printf("the len is -> %zu\n", ft_strlen(NULL));
//     printf("the len is -> %zu\n", ft_strlen(0));
//     printf("the len is -> %zu\n", ft_strlen("eyh"));
//     return (0);
// }
