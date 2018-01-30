/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/30 17:41:40 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pile	*new_pile(int len)
{
	t_pile *pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	pile->len = len;
	if (len > 0)
		pile->num = (int*)malloc(sizeof(int) * len);
	else
		pile->num = 0;
	return (pile);
}

void			pile_del(t_pile **pile)
{
	if (*pile)
	{
		free((*pile)->num);
		(*pile)->num = 0;
		free(*pile);
		*pile = 0;
	}
}

void display(int *list, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d\t",list[i]);
	printf("\n");
}
