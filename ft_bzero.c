/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:54:31 by arochd            #+#    #+#             */
/*   Updated: 2025/10/15 12:11:07 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *)s;
	if (!s && n > 0)
		return ;
	while (i < n)
	{
		buff[i] = '\0';
		i++;
	}
}
// #include<stdio.h>
// int main()
// {
//     // char buff[1000];
//     // for (int i = 0; i < 1000; i++)
//     //     buff[i] = 1;
//     // ft_bzero(buff, 1);
//     // ft_bzero(buff + 100, 1);
//     // int i = 0;
//     // while (i < 111)
//     // {
//     //     printf("%d", buff[i]);
//     //     i++;
//     // }
//     // printf("\n");
//     // char buf[] = "ABCD";
//     // ft_bzero(buf, 8);
//     // printf("\n\n");
//     // int j = 0;
//     // while (j < 8)
//     // {
//     //     printf("%d", buf[j]);
//     //     j++;
//     // char *ptr;
//     // ft_bzero(ptr, 10);
//     // char buf[10];
//     // ft_bzero(buf, (size_t)-1); // 
//Dangerous: Huge number, massive overflowstruct S { int x; d
//ouble y; char z[2]; } s = {1,
// 2.0, {'a', 'b'}};
//     // struct S { int x; double y; char z[2]; } s = {1, 2.0, {'a', 'b'}};
//     // ft_bzero(&s, sizeof(s));
//     // char buf[5] = {'A', 'B', 'C', 'D', 'E'};
//     // ft_bzero(buf, 0); // Should do nothing
//     return (0);
// }
