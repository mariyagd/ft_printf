/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:51:48 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/02 16:22:25 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int result = 0;
	int result1 = 0;

	char	c = '!';
	char	*s = "kitty";
	char	*s1 = ":)";
	char	*s2 = NULL;
	int		d = 0;	
	int		i = -545648;
	result = ft_printf("Hello %s %c %s %% %d %i %s",s, c, s1, d, i, s2);
	printf("\n");
	result1 = printf("Hello %s %c %s %% %d %i %s",s, c, s1, d, i, s2);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");

	char    *str = "kitty";
	int	*ptr1 = NULL;
    result = ft_printf("%%s = %s, %%p = %p %%p = %p", str, str, ptr1);
	printf("\n");
    result1 = printf("%%s = %s, %%p = %p %%p = %p", str, str, ptr1);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");

    char *ptr;
    ptr = NULL;
    result = ft_printf("%%p = %p", ptr);
    result1 = printf("%%p = %p", ptr);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");

    int     int_max = 2147483647;
    int     int_min = -2147483648;
    result = ft_printf("%%d = %d, %%i = %d", int_min, int_max);
	printf("\n");
    result1 = printf("%%d = %d, %%i = %d", int_min, int_max);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");

    int     c1 = 'a';
    int     c2 = 357;
    char    c3 = 'f';
    result = ft_printf("%%c = %c, %%c = %c, %%c = %c", c1, c2, c3);
	printf("\n");
    result1 = printf("%%c = %c, %%c = %c, %%c = %c", c1, c2, c3);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");
    
	unsigned int u1 = 4294967295;
    unsigned int u2 = 0;
    unsigned int u3 = -1;
    unsigned int u4 = -2147483648;
    unsigned int u5 = 2147483647;
    result = ft_printf("%%u = %u, %%u = %u, %%u = %u, %%u = %u, %%u = %u", u1, u2, u3, u4, u5);
	printf("\n");
    result1 = printf("%%u = %u, %%u = %u, %%u = %u, %%u = %u, %%u = %u", u1, u2, u3, u4, u5);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");


    unsigned int hex1 = 129866;
    unsigned int hex2 = 4294967295;
    unsigned int hex3 = -2147483648;
    unsigned int hex4 = 2147483647;
    result = ft_printf("%%x = %x, %%X = %X, %%x = %x, %%X = %x", hex1, hex2, hex3, hex4);
	printf("\n");
    result1 = printf("%%x = %x, %%X = %X, %%x = %x, %%X = %x", hex1, hex2, hex3, hex4);
	printf("\nresult = %d\n", result);
	printf("result1 = %d\n",result1);
	printf("\n");
   return (0);
}
