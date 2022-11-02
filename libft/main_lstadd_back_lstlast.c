/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstadd_back_lstlast.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:48:34 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/29 08:26:03 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"


void	del(void *ptr)
{
	free((t_list *)ptr);
}

int	main(void)
{
    t_list  *maillon0;
    t_list  *maillon1;
    t_list  *maillon2;
    t_list  *maillon3;
    char    *str0 = "Bonjour ";
    char    *str1 = "comment ";
    char    *str2 = "ca va? ";
    char    *str3 = ":)";

    maillon0 = ft_lstnew(str0);
    maillon1 = ft_lstnew(str1);
    maillon2 = ft_lstnew(str2);
    maillon3 = ft_lstnew(str3);

	t_list *maillon4;
	maillon4 = (t_list *)malloc(sizeof(t_list));
	maillon4->content = "hello";

	ft_lstdelone(maillon4, del);

	printf("\n-------------CREATION DE CHAQUE MAILLON-------------\n");
    printf("\nadresse maillon0 = %p, maillon0->content = %s,        maillon0->next = %p\n", maillon0, maillon0->content, maillon0->next);
    printf("adresse maillon1 = %p, maillon1->content = %s,        maillon1->next = %p\n", maillon1, maillon1->content, maillon1->next);
    printf("adresse maillon2 = %p, maillon2->content = %s,         maillon2->next = %p\n", maillon2, maillon2->content, maillon2->next);
    printf("adresse maillon3 = %p, maillon3->content = %s,              maillon3->next = %p\n", maillon3, maillon3->content, maillon3->next);

	printf("\n-------------LINKAGE ENTRE LES MAILLONS-------------\n");
	ft_lstadd_back(&maillon0, maillon1);
	printf("\nft_lstadd_back(&maillon0, maillon1)\n");
    printf("adresse maillon0 = %p, maillon0->content = \"%s\",        maillon0->next = %p  ", maillon0, maillon0->content, maillon0->next);
	printf("\nadresse maillon1 = %p, maillon1->content = \"%s\",        maillon1->next = %p  ", maillon1, maillon0->next->content, maillon0->next->next);
	printf("\n");


	ft_lstadd_back(&maillon0, maillon2);
	printf("\nft_lstadd_back(&maillon0, maillon2)\n");
    printf("adresse maillon0 = %p, maillon0->content = \"%s\",        maillon0->next = %p  ", maillon0, maillon0->content, maillon0->next);
    printf("\nadresse maillon1 = %p, maillon1->content = \"%s\",        maillon1->next = %p  ", maillon1, maillon0->next->content, maillon0->next->next);
	printf("\nadresse maillon2 = %p, maillon2->content = \"%s\",         maillon2->next = %p  ", maillon2, maillon0->next->next->content, maillon0->next->next->next);


	ft_lstadd_back(&maillon0, maillon3);
	printf("\n");
	printf("\nft_lstadd_back(&maillon0, maillon3)");
    printf("\nadresse maillon0 = %p, maillon0->content = \"%s\",        maillon0->next = %p  ", maillon0, maillon0->content, maillon0->next);
    printf("\nadresse maillon1 = %p, maillon1->content = \"%s\",        maillon1->next = %p  ", maillon1, maillon0->next->content, maillon0->next->next);
	printf("\nadresse maillon2 = %p, maillon2->content = \"%s\",         maillon2->next = %p  ", maillon2, maillon0->next->next->content, maillon0->next->next->next);
	printf("\nadresse maillon3 = %p, maillon3->content = \"%s\",              maillon3->next = %p  ", maillon3, maillon0->next->next->next->content, maillon0->next->next->next->next);
	printf("\n");

	printf("\n-------------DERNIER MAILLON-------------\n");
	printf("adresse maillon = %p, content = %s, next = %p\n", ft_lstlast(maillon0),ft_lstlast(maillon0)->content, ft_lstlast(maillon0)->next);
	
	printf("\n-------------TAILLE DE LA LISTE-------------\n");
	printf("%d\n", ft_lstsize(maillon0));

	t_list *ptr;
	ptr = maillon0->next;


	return (0);
}

