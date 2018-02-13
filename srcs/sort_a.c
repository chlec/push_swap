/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 17:40:59 by clecalie         ###   ########.fr       */
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

static void	in_a(t_stack *a, t_stack *b, int pivot, int lower)
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

void		sort_a(t_stack *a, t_stack *b, int pivot)
{
	int		lower;
	int		first;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	first = lowest_num(a, b);
	while (a->num[a->len - 1] != pivot)
	{
		lower = get_lower(a, b, first);
		/*ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);
		printf("le pivot est %d et le lower %d\n", pivot, lower);
		usleep(30000);*/
		if (is_in_stack(a, lower))
			in_a(a, b, pivot, lower);
		else
		{
			if (get_index(b, lower) < b->len / 2 + b->len % 2)
			{
				//Trier b jusqu'a sont pivot, laisser les plus petit ici
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
		if (b->len >= 2 && b->num[0] > b->num[b->len - 1] && b->num[0] > b->num [1])
		{
			ft_putendl("rr");
			rotate(b);
		}
		else
			ft_putendl("ra");
		rotate(a);
		a->sorted++;
	}
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