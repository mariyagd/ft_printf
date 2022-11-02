/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:27:59 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/29 23:47:45 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_format_specifier(const char *last, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, last);
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '%')
		{
			ft_putchar_fd(last[i], 1);
		}
		else if (last[i] == '%')
		{
			if (last[i + 1] == '%')
			{
				ft_putchar_fd(last[i], 1);
			}
			else if (last[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(ap, char *), 1);
			}
			else if (last[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
			}
			else if (last[i + 1] == 'u')
			{
				ft_u_putnbr_fd(va_arg(ap, unsigned int), 1);
			}
			else if (last[i + 1] == 'd' || last[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
			}
			else if (last[i + 1] == 'X')
			{
				ft_heXputnbr_fd(va_arg(ap, int), 1);
			}
			i++;
		}
		else if (last[i] == '/')
		{
			if (last[i + 1] == 'n')
				write(1, "\n", 2);
			i++;
		}
		i++;
	}
	va_end(ap);
}




int	main(void)
{
	char 	*str2 = "kitty";
	int		int_max = 2147483647;
	int		int_min	= -2147483648;
	int		c1 = 'a';
	int		c2 = 357;
	unsigned int u= 4294967295;
	int		hex = 129866;
	ft_format_specifier("hello %% %s %d %i %c %c %u %X j", str2, int_max, int_min, c1, c2, u, hex); 
	printf("\nhello %% %s %d %i %c %c %u %X j\n", str2, int_max, int_min, c1, c2, u, hex);

	int hex1 = 67890;
	int	hex2 = 19;
	ft_format_specifier("hello %X, %X", hex1, hex2);
	printf("\nhello %X, %X", hex1, hex2);
	printf("\n");
	ft_putchar_fd(c1, 1);
	ft_putchar_fd(c2, 1);
	printf("\n");
	write(1, "f", 1);
	return (0);
}

