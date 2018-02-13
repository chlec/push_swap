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

#include "push_swap.h"

int			lowest_num(t_stack *a, t_stack *b)
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

int			is_in_stack(t_stack *stack, int num)
{
	int 	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->num[i] == num)
			return (1);
		i++;
	}
	return (0);
}


int			higher(t_stack *a, t_stack *b)
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

int			get_index(t_stack *stack, int num)
{
	int		i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->num[i] == num)
			return (i);
		i++;
	}
	return (0);
}

int			get_lower(t_stack *a, t_stack *b, int first)
{
	int 	i;
	int		lower;

	lower = a->num[0] != first ? a->num[0] : higher(a, b);
	i = 0;
	while (i < b->len)
	{
		if (b->num[i] < lower)
			lower = b->num[i];
		i++;
	}
	i = 0;
	while (i < a->len && a->num[i] != first)
	{
		if (a->num[i] < lower && a->num[i] != first)
			lower = a->num[i];
		i++;
	}
	return (lower);
}
