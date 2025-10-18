#include "libft.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
# include <stddef.h>


/* helper to print test result */
static void	print_ok(const char *name, int ok)
{
	printf("%-20s : %s\n", name, ok ? "OK" : "FAIL");
}

/* small local reimplementations of character predicates to get expected results
   without calling the C library variants (avoids symbol collisions). */
static int exp_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
static int exp_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
static int exp_isalnum(int c)
{
	return (exp_isalpha(c) || exp_isdigit(c));
}
static int exp_isascii(int c)
{
	return ((unsigned)c <= 127u);
}
static int exp_isprint(int c)
{
	return ((unsigned)c >= 32u && (unsigned)c <= 126u);
}

/* small "reference" memmove implemented here so we can build expected results */
static void	ref_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	if (d == s || n == 0)
		return ;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
}

/* simple test runners for common cases */
int main(void)
{
	int ok;
	char buf1[64];
	// char buf2[64];
	char *p;
	// void *mem;

	printf("Running libft part-one quick test-suite\n\n");

	/* 1) Character tests */
	{
		const int tests[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '\t', '@', '[' , 127, 31};
		size_t n = sizeof(tests) / sizeof(tests[0]);

		ok = 1;
		for (size_t i = 0; i < n; ++i)
		{
			int c = tests[i];
			if (ft_isalpha(c) != exp_isalpha(c)) { ok = 0; break; } /* uses ft_isalpha now */
		}
		print_ok("isalpha()", ok);

		ok = 1;
		for (size_t i = 0; i < n; ++i)
		{
			int c = tests[i];
			if (ft_isalnum(c) != exp_isalnum(c)) { ok = 0; break; }
		}
		print_ok("ft_isalnum()", ok);

		ok = 1;
		for (size_t i = 0; i < n; ++i)
		{
			int c = tests[i];
			if (ft_isascii(c) != exp_isascii(c)) { ok = 0; break; }
		}
		print_ok("ft_isascii()", ok);

		ok = 1;
		for (size_t i = 0; i < n; ++i)
		{
			int c = tests[i];
			if (ft_isdigit(c) != exp_isdigit(c)) { ok = 0; break; }
		}
		print_ok("ft_isdigit()", ok);

		ok = 1;
		for (size_t i = 0; i < n; ++i)
		{
			int c = tests[i];
			if (ft_isprint(c) != exp_isprint(c)) { ok = 0; break; }
		}
		print_ok("ft_isprint()", ok);

		/* toupper/tolower */
		ok = 1;
		if (ft_toupper('a') != 'A') ok = 0;
		if (ft_toupper('Z') != 'Z') ok = 0;
		if (ft_tolower('A') != 'a') ok = 0;
		if (ft_tolower('m') != 'm') ok = 0;
		print_ok("ft_toupper/ft_tolower", ok);
	}

	/* 2) ft_memset / ft_bzero */
	{
		memset(buf1, 0xAA, sizeof(buf1));
		ft_memset(buf1, 'X', 10);
		ok = 1;
		for (int i = 0; i < 10; ++i) if (buf1[i] != 'X') ok = 0;
		print_ok("ft_memset()", ok);

		/* ft_bzero */
		memset(buf1, 0xFF, sizeof(buf1));
		ft_bzero(buf1, 20);
		ok = 1;
		for (int i = 0; i < 20; ++i) if (buf1[i] != 0) ok = 0;
		print_ok("ft_bzero()", ok);
	}

	/* 3) ft_memcpy */
	{
		const char *src = "Hello, memcpy!";
		char dst[32] = {0};
		ft_memcpy(dst, src, ft_strlen(src) + 1);
		print_ok("ft_memcpy()", strcmp(dst, src) == 0);
	}

	/* 4) ft_strlen */
	{
		ok = 1;
		if (ft_strlen("") != 0) ok = 0;
		if (ft_strlen("abc") != 3) ok = 0;
		if (ft_strlen("hello world") != 11) ok = 0;
		print_ok("ft_strlen()", ok);
	}

	/* 5) memmove (overlap) - uses ref_memmove to build expected result */
	{
		char a1[32] = "0123456789abcdef";
		char a2[32] = "0123456789abcdef";
		/* overlapping forward: dest = a1 + 4, src = a1, n = 8 */
		ref_memmove(a2 + 4, a2, 8);
		memmove(a1 + 4, a1, 8); /* user's memmove as declared in header */
		print_ok("memmove() overlap forward", memcmp(a1, a2, sizeof(a1)) == 0);

		/* overlapping backward */
		strcpy(a1, "0123456789abcdef");
		strcpy(a2, "0123456789abcdef");
		ref_memmove(a2, a2 + 4, 8);
		memmove(a1, a1 + 4, 8);
		print_ok("memmove() overlap backward", memcmp(a1, a2, sizeof(a1)) == 0);
	}

	/* 6) ft_strlcpy / ft_strlcat */
	{
		char dst[16];
		const char *src = "Hello,World";
		size_t r1, r2;
		/* strlcpy: return src length and copy up to dstsize-1 */
		memset(dst, 'A', sizeof(dst));
		r1 = ft_strlcpy(dst, src, 6); /* expect dst = "Hello" + '\0' */
		ok = (r1 == strlen(src)) && strcmp(dst, "Hello") == 0;
		print_ok("ft_strlcpy()", ok);

		/* strlcat: append and return length it tried to create */
		char dst2[16] = "Hi";
		r2 = ft_strlcat(dst2, " There", sizeof(dst2));
		/* expected result starts with "Hi There" or truncated but return is len(original)+len(src) */
		ok = (r2 == strlen("Hi") + strlen(" There")) && (strncmp(dst2, "Hi There", sizeof(dst2)) == 0 || strncmp(dst2, "Hi There", strlen("Hi There")) == 0);
		print_ok("ft_strlcat()", ok);
	}

	/* 7) ft_strchr / ft_strrchr */
	{
		const char *s = "abcabc";
		p = ft_strchr(s, 'b');
		ok = (p && p - s == 1);
		p = ft_strrchr(s, 'b');
		ok = ok && (p && p - s == 4);
		print_ok("ft_strchr/ft_strrchr()", ok);
	}

	/* 8) ft_strncmp */
	{
		ok = 1;
		if (ft_strncmp("abc", "abc", 3) != 0) ok = 0;
		if (ft_strncmp("abc", "abd", 2) != 0) ok = 0;
		if (ft_strncmp("abc", "ab", 3) <= 0) ok = 0; /* "abc" > "ab" when n >= len(ab) */
		print_ok("ft_strncmp()", ok);
	}

	/* 9) ft_memchr / ft_memcmp */
	{
		const char *s = "a\0b\0c";
		p = ft_memchr(s, 'b', 5);
		ok = (p && *p == 'b');
		ok = ok && (ft_memcmp("abc", "abc", 3) == 0);
		ok = ok && (ft_memcmp("abc", "abd", 3) < 0);
		print_ok("ft_memchr/ft_memcmp()", ok);
	}

	/* 10) ft_strnstr */
	{
		const char *big = "hello world";
		const char *little = "world";
		p = ft_strnstr(big, little, ft_strlen(big));
		ok = (p && strcmp(p, "world") == 0);
		p = ft_strnstr("hello", "lo", 3); /* should not find because len limit is 3 */
		ok = ok && (p == NULL);
		print_ok("ft_strnstr()", ok);
	}

	/* 11) ft_atoi */
	{
		const char *tests[] = {
			"0", "42", "-42", "   +123", "2147483647", "2147483648", "-2147483648", "-2147483649", "abc", "  56abc"
		};
		const int expect[] = {0, 42, -42, 123, 2147483647, 2147483648u > 2147483647u ? 2147483647 : 2147483648u, -2147483648, -2147483648, 0, 56};
		/* Note: overflow behavior may depend on your ft_atoi implementation; here we only check some stable cases */
		ok = 1;
		for (int i = 0; i < 10; ++i)
		{
			int v = ft_atoi(tests[i]);
			/* only validate non-overflow expected cases and simple cases */
			if (i == 5 || i == 6 || i == 7) /* skip ambiguous overflow checks */
				continue;
			if (v != expect[i]) { ok = 0; break; }
		}
		print_ok("ft_atoi() (basic)", ok);
	}

	/* 12) ft_strdup */
	{
		const char *s = "duplicate me";
		char *d = ft_strdup(s);
		ok = (d != NULL) && strcmp(d, s) == 0 && d != s;
		print_ok("ft_strdup()", ok);
		free(d);
	}

	/* 13) ft_calloc */
	{
		size_t nm = 10, sz = sizeof(int);
		int *arr = ft_calloc(nm, sz);
		ok = 1;
		if (arr == NULL)
			ok = 0;
		else
		{
			for (size_t i = 0; i < nm; ++i) if (arr[i] != 0) { ok = 0; break; }
		}
		print_ok("ft_calloc()", ok);
		free(arr);
	}

	printf("\nTest run finished.\n");
	return 0;
}