/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:20:17 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 10:54:54 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_count_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	else if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	return (count);
}
