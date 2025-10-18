/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:23:20 by arochd            #+#    #+#             */
/*   Updated: 2025/10/17 18:46:19 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return ((int)str1 - (int)str2);
		if (str1 == '\0')
			return (0);
		i++;
	}
	return (0);
}
