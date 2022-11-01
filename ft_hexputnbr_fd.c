/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexputnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:49 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/01 13:40:21 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	ft_hexputnbr_fd(unsigned int n, int fd)
{
	if (n > 15)
	{
		ft_hexputnbr_fd(n / 16, 1);
		ft_hexputnbr_fd(n % 16, 1);
	}
	if	(n < 10)
		ft_putchar_fd(n + 48, 1);
	else if (n > 9 && n < 16)
		ft_putchar_fd(n + 55, 1);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a = -1246;
	printf("%X\n",a);
	ft_hexputnbr_fd(a, 1);
}*/
