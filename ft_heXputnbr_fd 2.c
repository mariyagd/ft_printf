/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heXputnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:49 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/29 23:38:48 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

/*void	ft_heX_neg(int n, int fd)
{
	int	temp;
	
	temp = 0;
	n = n * (-1);
	while (n < 0)
	{
		write(1, "F", 1);
		temp = n % 10; 
		if (temp == 0)
			write(1, "F", 1);
		if (temp <= 8 && temp >= 1)
			ft_putchar_fd((char)(temp + 'A'), 1);
		if (temp >=9 && temp <= 15)
			ft_putchar_fd((char)(temp + 'D'), 1);
		n = n / 16;
	}
}*/

void	ft_heX_pos(int n, int fd)
{
	if (n > 15)
	{
		ft_heX_pos(n / 16, fd);
		ft_heX_pos((n % 16), fd);
	}
	else if (n <= 9 && n >= 0)
		ft_putchar_fd((char)(n + 48), fd);
	else if (n >=10 && n <= 15)
		ft_putchar_fd((char)(n + 55), fd);
}

void	ft_heXputnbr_fd(int n, int fd)
{
/*	if (n < 0)
		ft_heX_neg(n, fd);*/
	if (n >= 0)
		ft_heX_pos(n, fd);
}

/*#include <stdio.h>
int	main(void)
{
	int a = -11;
	int b = 3456;
//	ft_heXputnbr_fd(a, 1);
	printf("\n");
	ft_heXputnbr_fd(b, 1);
	printf("\n%X\n", a);
	printf("\n%X\n", b);
}*/
