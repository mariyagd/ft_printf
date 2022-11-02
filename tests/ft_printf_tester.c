/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:17:07 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/02 16:12:18 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <ft_printf.h>

#ifndef SHOW_OK
// set to 1 to show OK results
#define	SHOW_OK	0
#endif

#ifndef STOP
// set to 1 to stop at the first error
#define STOP 0
#endif

#define GRE "\e[32m"
#define RED	"\e[31m"
#define END	"\e[0m"

#define compare_noarg(format) \
	do { \
		_prepare(1); \
		i1 = printf(format); \
		_prepare(2); \
		i2 = ft_printf(format); \
		if (i1 != i2 || !equals()) { \
			msg("\n---\n"); \
			msg(RED "KO:" END " (\"" format "\")\n"); \
			msg2("expected: (retval = %d)\n", i1); \
			_print(1); \
			msg("\n"); \
			msg2("got: (retval = %d)\n", i2); \
			_print(2); \
			msg("\n---\n"); \
			if (stop) exit(EXIT_FAILURE); \
		} else if (show_ok) { \
			msg(GRE "OK:" END " (\"" format "\") "); \
		} \
	} while (0)


#define compare(format, ...) \
	do { \
		_prepare(1); \
		i1 = printf(format, __VA_ARGS__); \
		_prepare(2); \
		i2 = ft_printf(format, __VA_ARGS__); \
		if (i1 != i2 || !equals()) { \
			msg("\n---\n"); \
			msg(RED "KO:" END " (\"" format "\", " #__VA_ARGS__ ")\n"); \
			msg2("expected: (retval = %d)\n", i1); \
			_print(1); \
			msg("\n"); \
			msg2("got: (retval = %d)\n", i2); \
			_print(2); \
			msg("\n---\n"); \
			if (stop) exit(EXIT_FAILURE); \
		} else if (show_ok) { \
			msg(GRE "OK:" END " (\"" format "\", " #__VA_ARGS__ ") "); \
		} \
	} while (0)


void	msg(const char *msg)
{
	fputs(msg, stderr);
}

void	msg2(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
}

void	init(void)
{
	if (setvbuf(stdout, NULL, _IOLBF, 0) != 0)
	{
		msg("unable to reset buffering");
		exit(EXIT_FAILURE);
	}
}

void	_prepare(int i)
{
	if (!freopen(i == 1 ? "_test1" : "_test2", "w", stdout))
	{
		msg2("unable to open '_test%d' for writing", i);
		exit(EXIT_FAILURE);
	}
}

void	_print(int i)
{
	FILE	*f;
	char	c;
	size_t	sz;

	f = fopen(i == 1 ? "_test1" : "_test2", "r");
	if (!f)
	{
		msg2("unable to open '_test%d' for reading", i);
		exit(EXIT_FAILURE);
	}
	msg("\"");
	do {
		sz = fread(&c, sizeof(char), 1, f);
		if (sz)
			fputc(c, stderr);
		else if (ferror(f))
		{
			msg("unexpected error...");
			exit(EXIT_FAILURE);
		}
	}
	while (sz);
	msg("\"");
	fclose(f);
}

int	equals(void)
{
	int		ret;
	FILE	*f1, *f2;
	char	c1, c2;
	size_t	sz1, sz2;

	ret = 1;

	f1 = fopen("_test1", "r");
	if (!f1)
	{
		msg("unable to open '_test1' for reading");
		exit(EXIT_FAILURE);
	}
	f2 = fopen("_test2", "r");
	if (!f2)
	{
		msg("unable to open '_test2' for reading");
		exit(EXIT_FAILURE);
	}

	do {
		sz1 = fread(&c1, sizeof(char), 1, f1);
		sz2 = fread(&c2, sizeof(char), 1, f2);
		if (sz1 == 0 && sz2 == 0)
		{
			if (feof(f1) && feof(f2))
				goto finish;
			else
			{
				if (ferror(f1) || ferror(f2))
				{
					msg("unexpected error occurred...");
					exit(EXIT_FAILURE);
				}
				ret = 0;
				goto finish;
			}
		}
		if (sz1 != 1 || sz2 != 1 || c1 != c2)
		{
			ret = 0;
			goto finish;
		}
	}
	while (1);

finish:
	fclose(f1);
	fclose(f2);
	return (ret);
}

int	main(void)
{
	int			i1, i2;
	const int	show_ok = SHOW_OK;
	const int	stop = STOP;

	init();

	// simple strings
	compare_noarg("");
	compare_noarg("Hello World");
	compare_noarg(" ... ");

	// percents, simple
	//compare_noarg(" %  ");
	compare_noarg(" %% ");
	compare_noarg(" %% %% ");

	// c, simple
	compare(" %c ", 0);
	compare(" %c ", 42);
	compare(" %c ", -42);
	compare(" %c ", 1024);
	compare(" %c ", CHAR_MIN);
	compare(" %c ", CHAR_MAX);

	// d, simple
	compare(" %d ", 0);
	compare(" %d ", 42);
	compare(" %d ", -42);
	compare(" %d ", INT_MIN);
	compare(" %d ", INT_MAX);

	// i, simple
	compare(" %i ", 0);
	compare(" %i ", 42);
	compare(" %i ", -42);
	compare(" %i ", INT_MIN);
	compare(" %i ", INT_MAX);

	// u, simple
	compare(" %u ", 0);
	compare(" %u ", 42);
	compare(" %u ", -42);
	compare(" %u ", INT_MIN);
	compare(" %u ", INT_MAX);

	// x, simple
	compare(" %x ", 0);
	compare(" %x ", 42);
	compare(" %x ", -42);
	compare(" %x ", INT_MIN);
	compare(" %x ", INT_MAX);

	// X, simple
	compare(" %X ", 0);
	compare(" %X ", 42);
	compare(" %X ", -42);
	compare(" %X ", INT_MIN);
	compare(" %X ", INT_MAX);

	// p, simple
	compare(" %p ", 0);
	compare(" %p ", 42);
	compare(" %p ", -42);




#if 0
	// d, with length
	compare(" %hhd ", 0);
	compare(" %hhd ", 42);
	compare(" %hhd ", -42);
	compare(" %hhd ", CHAR_MIN);
	compare(" %hhd ", CHAR_MAX);

	compare(" %hd ", 0);
	compare(" %hd ", 42);
	compare(" %hd ", -42);
	compare(" %hd ", SHRT_MIN);
	compare(" %hd ", SHRT_MAX);

	compare(" %ld ", 0);
	compare(" %ld ", 42);
	compare(" %ld ", -42);
	compare(" %ld ", LONG_MIN);
	compare(" %ld ", LONG_MAX);

	compare(" %lld ", 0);
	compare(" %lld ", 42);
	compare(" %lld ", -42);
	compare(" %lld ", LLONG_MIN);
	compare(" %lld ", LLONG_MAX);



	// percents, complex (dummy args)
	compare_noarg(" %#% ");
	compare_noarg(" %# % ");
	compare_noarg(" %-% ");
	compare_noarg(" %-5% ");
	compare_noarg(" %.5% ");
	compare_noarg(" %.% ");
	compare_noarg(" % % ");
	compare_noarg(" %0% ");
	compare_noarg(" %05% ");
	compare_noarg(" %-# % ");
	compare_noarg(" %5% ");
	compare_noarg(" %l% ");

#endif
	fputs("\n===\n", stderr);
	return (EXIT_SUCCESS);
}
