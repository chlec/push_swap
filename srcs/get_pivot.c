/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:32:29 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 13:26:30 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		j = -1;
		while (++j < a->len)
			if (pivot < a->num[j])
				right++;
			else if (pivot > a->num[j])
				left++;
		i++;
	}
	return (pivot);
}

int		get_pivot_sort(t_stack *a, t_stack *b, int first, int b_len)
{
	int		i;
	int		j;
	int		pivot;
	int		left;
	int		right;

	while (b != NULL && b->len != 0)
		push(a, b);
	right = 1;
	i = -1;
	while (a->num[++i] != first && left != right)
	{
		right = a->len % 2;
		left = 0;
		pivot = a->num[i];
		j = -1;
		while (++j < a->len - a->sorted - 1)
			if (pivot < a->num[j])
				right++;
			else if (pivot > a->num[j])
				left++;
	}
	while (b != NULL && b->len < b_len)
		push(b, a);
	return (pivot);
}
