/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:09:48 by arochd            #+#    #+#             */
/*   Updated: 2025/10/14 22:51:09 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	if (!s ||!n)
		return (NULL);
	buff = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buff[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
// #include<stdio.h>
// int main()
// {
// 	// const char *ro = "hello";
// 	// ft_memset((void *)ro, 'A', 5); // Trying to write to string literal
// 	// char test[10];
// 	// ft_memset(test, 128, 10);
// 	// printf(" %s\n", test);
// 	// char buff[1];
// 	// ft_memset(buff, 'A', 10);
// 	return (0);
// }
// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char a[10];
// 	ft_memset(a, 'A', 10);
// 	//memset(a, 'A', 10);
// 	return 0;
// }
