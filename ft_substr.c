/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:58:12 by arochd            #+#    #+#             */
/*   Updated: 2025/10/18 16:20:42 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty(void)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	n;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_empty());
	n = len;
	if (n > s_len - (size_t)start)
		n = s_len - (size_t)start;
	substr = malloc (n + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
