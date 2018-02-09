/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:37:51 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 17:39:10 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int			lowest_num(t_pile *a, t_pile *b)
{
	int		best;
	int		i;

	best = a->num[0];
	i = 0;
	while (i < b->len)
	{
		if (b->num[i] < best)
			best = b->num[i];
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		if (a->num[i] < best)
			best = a->num[i];
		i++;
	}
	return (best);
}

int			is_in_stack(t_pile *pile, int num)
{
	int 	i;

	i = 0;
	while (i < pile->len)
	{
		if (pile->num[i] == num)
			return (1);
		i++;
	}
	return (0);
}


int			higher(t_pile *a, t_pile *b)
{
	int		best;
	int		i;

	best = a->num[0];
	i = 0;
	while (i < b->len)
	{
		if (b->num[i] > best)
			best = b->num[i];
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		if (a->num[i] > best)
			best = a->num[i];
		i++;
	}
	return (best);
}

int			get_index(t_pile *pile, int num)
{
	int		i;

	i = 0;
	while (i < pile->len)
	{
		if (pile->num[i] == num)
			return (i);
		i++;
	}
	return (0);
}
