/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:41:08 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 13:32:17 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_last_b_numbers(t_stack *a, t_stack *b)
{
	if (b->len == 2 && b->num[0] < b->num[1])
	{
		ft_putendl("sb");
		swap(b);
	}
	while (b->len > 0)
	{
		ft_putendl("pa");
		push(a, b);
	}
	ft_putendl("ra");
	rotate(a);
}

void		sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		len;
	int		i;

	len = b->len;
	if (b->len <= 2)
		return (push_last_b_numbers(a, b));
	pivot = get_pivot(b);
	i = 0;
	while (i < len)
	{
		if (b->num[0] > pivot)
		{
			ft_putendl("pa");
			push(a, b);
		}
		else
		{
			ft_putendl("rb");
			rotate(b);
		}
		i++;
	}
	sort_b(a, b);
}
