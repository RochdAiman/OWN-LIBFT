/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:27:22 by arochd            #+#    #+#             */
/*   Updated: 2025/10/15 17:27:25 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*dst;
	size_t			i;

	if ((!dest && !src) && n > 0)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	source = (char *)src;
	dst = (char *)dest;
	if (dst < source || dst >= source + n)
	{
		i = -1;
		while (++i < n)
			dst[i] = source[i];
	}
	else
	{
		i = n;
		while (i--)
			dst[i] = source[i];
	}
	return (dest);
}
