/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:41:02 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 10:55:56 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_unsint(unsigned int n, int fd, int *count)
{
	ft_put_unsnbr_fd(n, fd);
	*count += ft_count_unsigned_int(n);
}
