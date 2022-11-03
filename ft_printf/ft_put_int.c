/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:22:21 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 10:56:09 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_int(int n, int fd, int *count)
{
	int	a;

	a = *count;
	ft_putnbr_fd(n, fd);
	a += ft_count_int(n);
	return (a);
}
