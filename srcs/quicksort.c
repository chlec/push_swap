/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/08 13:55:56 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int		get_pivot(t_pile *pile)
{
	int		i;
	int		j;
	int		pivot;
	int		left;
	int		right;

	i = 0;
	left = 0;
	right = 1;
	while (i < pile->len && left != right)
	{
		right = !(pile->len % 2);
		left = 0;
		pivot = pile->num[i];
		j = 0;
		while (j < pile->len)
		{
			if (pivot < pile->num[j])
				right++;
			if (pivot > pile->num[j])
				left++;
			j++;
		}
		i++;
	}
	return (pivot);
}

/*int			lower_stack(t_pile *a)
{
	int		i;
	int		lower;

	lower = a->len[0];
	i = 0;
	while (i < a->len)
	{
		if (a->num[i] < lower && a->num[i] > num)
		{
			lower = a->num[i];
		}
		i++;
	}
}*/

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

void		autre_tri(t_pile *a, t_pile *b, int end)
{
	int		i;
	int		j;
	int		num;
	int		lower;
	int		pivot;
	int		first;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	num = 0;
	pivot = get_pivot(a);
	first = 0;
	while (a->num[a->len - 1] != end)
	{
		lower = a->num[0] != 0 ? a->num[0] : higher(a, b);
	/*	ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);*/
		j = 0;
		while (j < b->len)
		{
			if (b->num[j] < lower)
				lower = b->num[j];
			j++;
		}
		i = 0;
		while (i < a->len && a->num[i] != first)
		{
			if (a->num[i] < lower && a->num[i] != 0)
				lower = a->num[i];
			i++;
		}
		if (is_in_stack(a, lower))
		{
			while (a->num[0] != lower)
			{
				ft_putendl("pb");
				push(b, a);
			}
		}
		else if (is_in_stack(b, lower))
		{
			if (get_index(b, lower) < b->len / 2)
			{
				while (b->num[0] != lower)
				{
					ft_putendl("rb");
					rotate(b);
				}
			}
			else
			{
				while (b->num[0] != lower)
				{
					ft_putendl("rrb");
					rev_rotate(b);
				}
			}
			ft_putendl("pa");
			push(a, b);
		}
		ft_putendl("ra");
		rotate(a);
	}
	if (end == higher(a, b))
	{
		while (b->len > 0)
		{
			ft_putendl("pa");
			push(a, b);
		}
	}
	if (a->num[a->len - 1] == 50)
		autre_tri(a, b, 75);
	if (a->num[a->len - 1] == 75)
		autre_tri(a, b, 100);
}

void 		quick2(t_pile *a, t_pile *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = b->len;
	pivot = get_pivot(b);
	if (b->len == 2)
	{
		if (b->num[0] < b->num[1])
		{
			ft_putendl("sb");
			swap(b);
		}
		ft_putendl("pa");
		push(a, b);
		ft_putendl("pa");
		push(a, b);
		ft_putendl("ra");
		rotate(a);
		autre_tri(a, b, get_pivot(a));
		//		short_sort(a, b);
		return ;
	}
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
	quick2(a, b);
}

void 		quicksort(t_pile *a, t_pile *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = a->len;
	pivot = get_pivot(a);
	if (check_stack(a))
	{
		short_sort(a, b);
		return ;
	}
	while (i < len)
	{
		if (a->num[0] < pivot)
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
	quick2(a, b);
}
