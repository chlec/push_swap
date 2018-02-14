/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 13:33:02 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	short_sort_2(t_stack *a, t_stack *b)
{
	if (check_stack(a) == 1 && b->num[0] < a->num[0])
	{
		ft_putendl("pa");
		push(a, b);
	}
	else if ((a->num[0] < a->num[1]) && (b->len == 0 || a->num[0] > b->num[0]))
	{
		ft_putendl("pb");
		push(b, a);
	}
	else if (a->num[0] > a->num[a->len - 1])
	{
		ft_putendl("ra");
		rotate(a);
	}
	else if (a->len > 1)
	{
		ft_putendl("pb");
		push(b, a);
	}
}

void		short_sort(t_stack *a, t_stack *b)
{
	while (!check_valid(a, b))
	{
		if (a->num[0] > a->num[a->len - 1])
		{
			ft_putendl("ra");
			rotate(a);
		}
		else if (a->len > 1 && a->num[0] > a->num[1])
		{
			ft_putendl("sa");
			swap(a);
		}
		else if (b->len > 1 && b->num[0] < b->num[b->len - 1])
		{
			ft_putendl("rb");
			rotate(b);
		}
		else if (b->len > 1 && b->num[0] < b->num[1])
		{
			ft_putendl("sb");
			swap(b);
		}
		else
			short_sort_2(a, b);
	}
}
