/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:39:11 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/02 14:49:14 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_put_unsnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_put_unsnbr_fd(n / 10, fd);
		ft_put_unsnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((char)(n + 48), fd);
}
