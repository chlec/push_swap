/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 13:38:24 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_stack(t_stack *a, t_stack *b, int pivot, int first)
{
	if (pivot == higher(a, b))
	{
		while (b->len > 0)
		{
			ft_putendl("pa");
			push(a, b);
		}
	}
	if (a->num[a->len - 1] != higher(a, b))
	{
		pivot = get_pivot_sort(a, b, first, b->len);
		split_to_pivot(a, b, pivot);
		sort_a(a, b, pivot);
	}
}

static void	sort_first_part_b(t_stack *a, t_stack *b, int lower, int first)
{
	while (b->len >= 2 && b->num[0] != lower && b->num[1] != lower)
	{
		ft_putendl("rb");
		rotate(b);
	}
	if (b->len > 1 && b->num[1] == lower)
	{
		if (a->len >= 2 && a->num[0] > a->num[1] && a->num[1] != first)
		{
			ft_putendl("ss");
			swap(b);
			swap(a);
		}
		else
		{
			ft_putendl("sb");
			swap(b);
		}
	}
}

static void	sort_second_part_b(t_stack *b, int lower)
{
	while (b->num[0] != lower)
	{
		ft_putendl("rrb");
		rev_rotate(b);
	}
}

void		sort_a(t_stack *a, t_stack *b, int pivot)
{
	int		lower;
	int		first;

	first = lowest_num(a, b);
	while (a->num[a->len - 1] != pivot)
	{
		lower = get_lower(a, b, first);
		if (is_in_stack(a, lower))
			lower_in_a(a, b, pivot, lower);
		else
		{
			if (get_index(b, lower) < b->len / 2 + b->len % 2)
				sort_first_part_b(a, b, lower, first);
			else
				sort_second_part_b(b, lower);
			ft_putendl("pa");
			push(a, b);
		}
		ft_putendl("ra");
		rotate(a);
		a->sorted++;
	}
	update_stack(a, b, pivot, first);
}
