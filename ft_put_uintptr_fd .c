/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uintptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:49 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/01 14:09:11 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	ft_put_uintptr_fd(uintptr_t n, int fd)
{

	if (n > 15)
	{
		ft_put_uintptr_fd(n / 16, 1);
		ft_put_uintptr_fd(n % 16, 1);
	}
	if	(n < 10)
		ft_putchar_fd(n + 48, 1);
	else if (n > 9 && n < 16)
		ft_putchar_fd(n + 87, 1);
}

void ft_put_ptr_adress(uintptr_t n, int fd)
{
	write(1, "0x", 2);
	ft_put_uintptr_fd(n, 1);
}

/*
#include <stdio.h>
int	main(void)
{
	int		a = 1246;
	uintptr_t b = (uintptr_t)&a;
	printf("%p\n",&a);
//	write(1, "0x", 2);
	ft_put_ptr_adresse(b, 1);
}*/

