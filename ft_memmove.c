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
	unsigned char	*source;
	unsigned char	*dst;
	size_t			i;

	if ((!dest || !src) && n > 0)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	source = (unsigned char *)src;
	dst = (unsigned char *)dest;
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
// #include<stdio.h>
// #include<string.h>
// void print_buffers(const char *label, char *a, char *b, size_t len) {
//     printf("%s\nMine:    \"%.*s\"\nStandard:\"%.*s\"
//\n\n", label, (int)len, a, (int)len, b);
// }

// int main() {
//     char src[32], mine[32], std[32];

//     // 1. Simple non-overlapping forward
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 5, src, 5);
//     memmove(std + 5, src, 5);
//     print_buffers("Test 1: Non-overlap forward", mine, std, 10);

//     // 2. Simple overlapping forward (src < dest)
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 2, mine, 8);
//     memmove(std + 2, std, 8);
//     print_buffers("Test 2: Overlap, src < dest", mine, std, 10);

//     // 3. Simple overlapping backward (dest < src)
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine, mine + 2, 8);
//     memmove(std, std + 2, 8);
//     print_buffers("Test 3: Overlap, dest < src", mine, std, 10);

//     // 4. Whole buffer copy to self
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine, mine, 10);
//     memmove(std, std, 10);
//     print_buffers("Test 4: Copy to self", mine, std, 10);

//     // 5. Zero length
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 3, mine, 0);
//     memmove(std + 3, std, 0);
//     print_buffers("Test 5: Zero length", mine, std, 10);

//     // 6. Single byte overlap
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 1, mine, 1);
//     memmove(std + 1, std, 1);
//     print_buffers("Test 6: 1 byte overlap", mine, std, 10);

//     // 7. Non-overlapping, partial copy
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine, src + 5, 5);
//     memmove(std, src + 5, 5);
//     print_buffers("Test 7: Non-overlap partial", mine, std, 10);

//     // 8. Overlap, full buffer, dest > src
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 1, mine, 9);
//     memmove(std + 1, std, 9);
//     print_buffers("Test 8: Overlap, full buffer", mine, std, 10);

//     // 9. Overlap, dest < src
//     strcpy(src, "abcdefghij");
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine, mine + 1, 9);
//     memmove(std, std + 1, 9);
//     print_buffers("Test 9: Overlap, dest < src", mine, std, 10);

//     // 10. Large buffer, partial overlap
//     memset(src, 'X', 31); src[31] = '\0';
//     strcpy(mine, src);
//     strcpy(std, src);
//     ft_memmove(mine + 10, mine, 15);
//     memmove(std + 10, std, 15);
//     print_buffers("Test 10: Large partial overlap", mine, std, 30);

//     return 0;
// }
// // // // // // int main()
// // // // // // {
// // // // // // 	char dst[] = "ABCDEF";
// // // // // // 	char src[] = "GHLMNPO";
// // // // // // 	ft_memmove(dst, src, sizeof(dst));
// // // // // // 	printf("%s\n", dst);
// // // // // // 	return (0);
// // // // // // }
// // int main()
// // {
// //     char buffer[20] = "ABCDEFGHIJKLMNO";

// //     // Overlapping: dest and src overlap in buffer
// //     // Copy 10 bytes from buffer[0] ("A") to buffer[5] ("F")
// //     ft_memmove(buffer + 5, buffer, 10);

// //     // Expected result:
// //     // buffer: "ABCDEABCDEFGHIJ"
// //     //          ^    ^^^^^^^^^^
// //     //          |    copied from original start
// //     printf("After overlap memmove: %s\n", buffer);

// //     // For reference, compare with standard memmove
// //     char ref[20] = "ABCDEFGHIJKLMNO";
// //     memmove(ref + 5, ref, 10);
// //     printf("Standard memmove:     %s\n", ref);

// //     return 0;
// // }
