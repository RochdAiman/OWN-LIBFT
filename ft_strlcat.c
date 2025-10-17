/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:36:23 by arochd            #+#    #+#             */
/*   Updated: 2025/10/17 11:32:30 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	d_len = 0;
	while (d_len < dst_size && dst[d_len])
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (d_len == dst_size)
		return (d_len + s_len);
	i = 0;
	while (i < dst_size - d_len - 1 && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include<stdio.h>
// int main()
// {
//     char dst[] = "FORZA";
//     char src[] = "NAPOLI";
//     int total = ft_strlcat(dst, src, sizeof(dst));
//     printf("%d\n", total);
//     return (0);
// }
// #include <stdio.h>
// #include <string.h>
// #include <stddef.h>

// /* Declare the prototypes that match the correct signatures */
// size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = 0;
// 	if (!src ||!dst)
// 		return (0);
// 	while (src[src_len])
// 		src_len++;
// 	if (dst_size == 0)
// 		return (src_len);
// 	if (dst_size > 0)
// 	{
// 		while (src[i] && i < dst_size -1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

// /* Reference implementations (same behavior as BSD functions) */
// size_t ref_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t i = 0;
// 	if (dstsize) {
// 		while (src[i] && i < dstsize - 1) {
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	while (src[i]) i++;
// 	return i;
// }

// size_t ref_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t dlen = 0, slen = 0, i;
// 	while (dlen < dstsize && dst[dlen]) dlen++;
// 	while (src[slen]) slen++;
// 	if (dlen == dstsize) return dstsize + slen;
// 	i = 0;
// 	while (i < dstsize - dlen - 1 && src[i]) {
// 		dst[dlen + i] = src[i];
// 		i++;
// 	}
// 	dst[dlen + i] = '\0';
// 	return dlen + slen;
// }

// /* Helper to run a single comparison and print result */
// static void run_cmp_strlcpy(const char *src, size_t dstsize)
// {
// 	char mine[64], ref[64];
// 	size_t r1, r2;

// 	memset(mine, 'X', sizeof(mine));
// 	memset(ref, 'X', sizeof(ref));
// 	mine[sizeof(mine)-1] = ref[sizeof(ref)-1] = '\0';

// 	r1 = ft_strlcpy(mine, src, dstsize);
// 	r2 = ref_strlcpy(ref, src, dstsize);

// 	printf("strlcpy src=\"%s\" dstsize=%zu\n", src[0] ? src : "\\0", dstsize);
// 	printf(" Mine: \"%s\" (ret=%zu)\n Ref.: \"%s\" (ret=%zu
//)\n\n", mine, r1, ref, r2);
// }

// static void run_cmp_strlcat(const ch
//ar *dst_init, const char *src, size_t dstsize)
// {
// 	char mine[64], ref[64];
// 	size_t r1, r2;

// 	memset(mine, 'X', sizeof(mine));
// 	memset(ref, 'X', sizeof(ref));
// 	/* place initial dst content (bounded) */
// 	strncpy(mine, dst_init, sizeof(mine)-1);
// 	strncpy(ref, dst_init, sizeof(ref)-1);
// 	mine[sizeof(mine)-1] = ref[sizeof(ref)-1] = '\0';

// 	r1 = ft_strlcat(mine, src, dstsize);
// 	r2 = ref_strlcat(ref, src, dstsize);

// 	printf("strlcat dst_init=\"%s\" src=\"%s\" dstsize=%zu\n"
//, dst_init, src, dstsize);
// 	printf(" Mine: \"%s\" (ret=%zu)\n Ref.: 
//"%s\" (ret=%zu)\n\n", mine, r1, ref, r2);
// }

// int main(void)
// {
// 	/* 10 tests for strlcpy */
// 	const char *cpy_srcs[10] = {
// 		"Hello", "Hello, world!", "Hello", "", "Hello",
// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcd", "short", "ab\0cde", ""
// 	};
// 	size_t cpy_sizes[10] = {10, 6, 0, 10, 1, 5, 5, 50, 10, 10};

// 	printf("=== strlcpy tests ===\n\n");
// 	for (int i = 0; i < 10; ++i)
// 		run_cmp_strlcpy(cpy_srcs[i], cpy_sizes[i]);

// 	/* 10 tests for strlcat */
// 	const char *cat_dst_inits[10] = {
// 		"Hello", "Hello", "Hello", "", "A",
// 		"Hello", "ABCDEFG", "abcd", "short", "Hi"
// 	};
// 	const char *cat_srcs[10] = {
// 		"World", "World!!!", "X", "abc", "BC",
// 		"", "xyz", "ef", "append", "abcdefghijklmnopqrstuvwxyz"
// 	};
// 	size_t cat_sizes[10] = {12, 10, 0, 5, 1, 10, 3, 7, 50, 6};

// 	printf("=== strlcat tests ===\n\n");
// 	for (int i = 0; i < 10; ++i)
// 		run_cmp_strlcat(cat_dst_inits[i], cat_srcs[i], cat_sizes[i]);

// 	return 0;
// }
