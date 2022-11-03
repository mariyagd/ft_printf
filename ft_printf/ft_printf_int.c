/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:55 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 11:04:40 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_int(int n, int fd, int *count)
{
	ft_putnbr_fd(n, fd);
	*count += ft_count_int(n);
}
