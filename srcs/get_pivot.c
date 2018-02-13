/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:32:29 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 17:35:35 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int		get_pivot(t_stack *a)
{
	int		i;
	int		j;
	int		pivot;
	int		left;
	int		right;

	i = 0;
	left = 0;
	right = 1;
	while (left != right)
	{
		right = !(a->len % 2);
		left = 0;
		pivot = a->num[i];
		j = 0;
		while (j < a->len)
		{
			if (pivot < a->num[j])
				right++;
			if (pivot > a->num[j])
				left++;
			j++;
		}
		i++;
	}
	return (pivot);
}

int		get_pivot_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		pivot;
	int		left;
	int		right;
	int		total;
	int		first;

	total = b->len;
	while (b->len != 0)
		push(a, b);
	first = lowest_num(a, b);
	left = 0;
	right = 1;
	i = 0;
	while (i < a->len - a->sorted - 1 && a->num[i] != first && left != right)
	{
		right = !(a->len - a->sorted % 2);
		left = 0;
		pivot = a->num[i];
		j = 0;
		while (j < a->len - a->sorted)
		{
			if (pivot < a->num[j])
				right++;
			if (pivot > a->num[j])
				left++;
			j++;
		}
		i++;
	}
	while (b->len < total)
		push(b, a);
	return (pivot);
}
