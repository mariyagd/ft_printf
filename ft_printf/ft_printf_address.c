/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:50:18 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 10:55:06 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_put_uintptr_fd(uintptr_t n, int fd, int *count);

void	ft_printf_address(uintptr_t n, int fd, int *count)
{
	ft_printf_str("0x", fd, count);
	ft_put_uintptr_fd(n, fd, count);
}

void	ft_put_uintptr_fd(uintptr_t n, int fd, int *count)
{
	if (n > 15)
	{
		ft_put_uintptr_fd(n / 16, fd, count);
		ft_put_uintptr_fd(n % 16, fd, count);
	}
	if (n < 10)
		ft_printf_char(n + 48, fd, count);
	else if (n > 9 && n < 16)
		ft_printf_char(n + 87, fd, count);
}
