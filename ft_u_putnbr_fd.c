/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:49 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/29 16:21:22 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	ft_u_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_u_putnbr_fd(n / 10, fd);
		ft_u_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((char)(n + 48), fd);
}
