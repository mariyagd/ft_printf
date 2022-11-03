/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:08:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 10:54:47 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_count_int(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	if (n < 0)
	{
		while (n < 0)
		{
			n = n / 10;
			count++;
		}
		count++;
	}
	return (count);
}
