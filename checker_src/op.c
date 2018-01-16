/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:19:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/15 17:02:56 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Push first element of b to a
*/

void	push(t_pile *a, t_pile *b)
{
	int		j;

	j = a->len;
	while (j >= 0)
	{
		a->num[j + 1] = a->num[j];
		j--;
	}
	a->num[0] = b->num[0];
	j = 0;
	while (j < b->len)
	{
		b->num[j] = b->num[j + 1];
		j++;
	}
	a->len++;
	b->len--;
}

/*
** Move every elements to the bottoem. the last become the first
*/

void	rev_rotate(t_pile *pile)
{
	int		temp;
	int		j;

	temp = pile->num[pile->len - 1];
	j = pile->len;
	while (j >= 0)
	{
		pile->num[j + 1] = pile->num[j];
		j--;
	}
	pile->num[0] = temp;
}

/*
** Move every elements to the top. the first become the last
*/

void	rotate(t_pile *pile)
{
	int		j;
	int		temp;

	temp = pile->num[0];
	j = 0;
	while (j + 1 < pile->len)
	{
		pile->num[j] = pile->num[j + 1];
		j++;
	}
	pile->num[j] = temp;
}

/*
** Swap the two first elements of a stack
*/

void	swap(t_pile *pile)
{
	int		temp;

	temp = pile->num[0];
	pile->num[0] = pile->num[1];
	pile->num[1] = temp;
}