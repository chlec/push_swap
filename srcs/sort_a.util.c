/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:43:40 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 12:43:47 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_number_on_right(t_stack *a, t_stack *b, int on_right)
{
	ft_putendl("pb");
	push(b, a);
	while (on_right > 0)
	{
		if (b->len >= 2 && b->num[0] > b->num[1] && b->num[0] > b->num[b->len - 1])
		{
			ft_putendl("rrr");
			rev_rotate(b);
			rev_rotate(a);
		}
		else
		{
			ft_putendl("rra");
			rev_rotate(a);
		}
		on_right--;
	}
	ft_putendl("pa");
	push(a, b);
}

static void	swap_a(t_stack *a, t_stack *b, int lower)
{
	if (a->num[1] == lower)
	{
		if (b->len >= 2 && b->num[0] > b->num[1])
		{
			ft_putendl("ss");
			swap(b);
			swap(a);
		}
		else
		{
			ft_putendl("sa");
			swap(a);
		}
	}
}

void		lower_in_a(t_stack *a, t_stack *b, int pivot, int lower)
{
	int 	on_right;

	on_right = 0;
	while (a->num[0] != lower && a->num[1] != lower)
	{
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
	}
	if (on_right > 0)
		move_number_on_right(a, b, on_right);
	swap_a(a, b, lower);
}