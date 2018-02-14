/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 12:31:42 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_pivot(t_stack *a, t_stack *b, int pivot)
{
	int		first;
	int		on_right;

	first = lowest_num(a, b);
	on_right = 0;
	while (a->num[0] != first)
		if (a->num[0] > pivot)
		{
			ft_putendl("ra");
			rotate(a);
			on_right++;
		}
		else
		{
			ft_putendl("pb");
			push(b, a);
		}
	while (on_right > 0)
	{
		ft_putendl("rra");
		rev_rotate(a);
		on_right--;
	}
	sort_b(a, b);
}

void 		quicksort(t_stack *a, t_stack *b)
{
	int		pivot;
	int		len;
	int		i;

	len = a->len;
	i = 0;
	pivot = get_pivot(a);
	if (check_stack(a))
		return short_sort(a, b);
	while (i < len)
	{
		if (a->num[0] <= pivot)
		{
			ft_putendl("pb");
			push(b, a);
		}
		else
		{
			ft_putendl("ra");
			rotate(a);
		}
		i++;
	}
	sort_b(a, b);
	sort_a(a, b, pivot);
}
