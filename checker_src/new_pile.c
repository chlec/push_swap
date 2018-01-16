/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/16 11:49:02 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pile	*new_pile(int len)
{
	t_pile *pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	pile->len = len;
	pile->num = (int*)malloc(sizeof(int) * len);
	return (pile);
}

void	free_pile(t_pile **pile)
{
	if (*pile)
	{
		if ((*pile)->num)
			free((*pile)->num);
		(*pile)->num = 0;
		(*pile)->len = 0;
		free(*pile);
	}
}