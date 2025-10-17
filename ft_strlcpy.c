/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:49 by arochd            #+#    #+#             */
/*   Updated: 2025/10/16 11:56:18 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (!src ||!dst)
		return (0);
	while (src[src_len])
		src_len++;
	if (dst_size == 0)
		return (src_len);
	if (dst_size > 0)
	{
		while (src[i] && i < dst_size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
// // #include<stdio.h>
// // #include<string.h>
// // int main()
// // {
// //     char src[] = "HELLO";
// //     char dst[5];
// //     printf("%zu\n", ft_strlcpy(dst, src, sizeof(dst)));
// //     // printf("%zu\n", ft_strlcpy(dst, src, sizeof(dst)) -2);
// //     return(0);
// // }
// #include <stdio.h>
// #include <string.h>

// // If your system doesn't have strlcpy, use this reference implementation:
// size_t std_strlcpy(char *dst, const char *src, size_t dstsize)
// {
//     size_t i = 0;
//     if (dstsize) {
//         while (src[i] && i < dstsize - 1) {
//             dst[i] = src[i];
//             i++;
//         }
//         dst[i] = '\0';
//     }
//     while (src[i])
//         i++;
//     return i;
// }

// // Your ft_strlcpy prototype
// size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

// void print_result(const char *label, char *mine, 
//char *std, size_t ret_mine, size_t ret_std) {
//     printf("%s\nMine:    \"%s\" (ret=%zu)\nS
//tandard:\"%s\" (ret=%zu)\n\n", label, mine, ret_mine, std, ret_std);
// }

// int main(void)
// {
//     char mine[50], std[50];
//     size_t ret_mine, ret_std;

//     // Test 1: Regular copy, fits
//     ret_mine = ft_strlcpy(mine, "Hello", 10);
//     ret_std  = std_strlcpy(std, "Hello", 10);
//     print_result("Test 1: Regular copy, fits", mine, std, ret_mine, ret_std);

//     // Test 2: Truncated copy
//     ret_mine = ft_strlcpy(mine, "Hello, world!", 6);
//     ret_std  = std_strlcpy(std, "Hello, world!", 6);
//     print_result("Test 2: Truncated copy", mine, std, ret_mine, ret_std);

//     // Test 3: dstsize == 0
//     ret_mine = ft_strlcpy(mine, "Hello", 0);
//     ret_std  = std_strlcpy(std, "Hello", 0);
//     print_result("Test 3: dstsize == 0", mine, std, ret_mine, ret_std);

//     // Test 4: src is empty string
//     ret_mine = ft_strlcpy(mine, "", 10);
//     ret_std  = std_strlcpy(std, "", 10);
//     print_result("Test 4: src empty string", mine, std, ret_mine, ret_std);

//     // Test 5: dstsize == 1
//     ret_mine = ft_strlcpy(mine, "Hello", 1);
//     ret_std  = std_strlcpy(std, "Hello", 1);
//     print_result("Test 5: dstsize == 1", mine, std, ret_mine, ret_std);

//     // Test 6: src longer than dstsize
//     ret_mine = ft_strlcpy(mine, "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
// 5);
//     ret_std  = std_strlcpy(std, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5);
//     print_result("Test 6: src longer than dstsiz
//e", mine, std, ret_mine, ret_std);

//     // Test 7: src fits exactly
//     ret_mine = ft_strlcpy(mine, "abcd", 5);
//     ret_std  = std_strlcpy(std, "abcd", 5);
//     print_result("Test 7: src fits exactly", mine, std, ret_mine, ret_std);

//     // Test 8: src is 
//much longer, small buffer
//     ret_mine = ft_strlcpy(mine, "abcdefghijklmnopqrstuvwxyz", 8);
//     ret_std  = std_strlcpy(std, "abcdefghijklmnopqrstuvwxyz", 8);
//     print_result("Test 8: src much longer, small buff
//er", mine, std, ret_mine, ret_std);

//     // Test 9: dstsize very large
//     ret_mine = ft_strlcpy(mine, "short", 50);
//     ret_std  = std_strlcpy(std, "short", 50);
//     print_result("Test 9: dstsize very large", mine, std, ret_mine, ret_std);

//     // Test 10: src is just '\0'
//     ret_mine = ft_strlcpy(mine, "\0", 10);
//     ret_std  = std_strlcpy(std, "\0", 10);
//     print_result("Test 10: src is just '\\0'", mine, std, ret_mine, ret_std);

//     return 0;
// }
