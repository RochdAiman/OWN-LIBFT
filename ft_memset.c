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

	buff = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buff[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
#include<stdio.h>
int main()
{
	int i = 10;
	int j = 20;
	int tmp;
	ft_memset(&tmp, i, 1);
	ft_memset(&i, j, 1);
	ft_memset(&j, tmp, 1);
	printf("the value of i = %d\n", i);
	printf("the value of j = %d\n", j);
}