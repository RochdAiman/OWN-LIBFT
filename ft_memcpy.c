/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:17:44 by arochd            #+#    #+#             */
/*   Updated: 2025/10/15 17:13:20 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	i = 0;
	if ((!dest || !src) && n > 0)
		return (NULL);
	if (n == 0)
		return (dest);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
//#include<stdio.h>
//int main()
//{
	// char buff1[] = "NAPOLI";
	// char buff2[7];
	// ft_memcpy(buff2, buff1, 7);
	// printf("%s", buff2);
	// int src[] = {1, 2, 3, 4, 5};
	// int dst[5];
	// ft_memcpy(dst, src, sizeof(src));
	// int i = 0;
	// while (i < 5)
	// {
	// 	printf("%d\n", dst[i]);
	// 	i++;
	// }
	// char *src = NULL;
//	char *dst = "hh";
//	ft_memcpy(dst, NULL, 2);
//
//	return(0);
//}
