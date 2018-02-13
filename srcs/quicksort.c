/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 17:40:59 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void		quick3(t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	int		pivot;

	if (b->len > 0)
	{
		i = 0;
		pivot = get_pivot(b);
		while (i < b->len)
		{
			if (b->num[i] < pivot)
			{
				ft_putendl("rb");
				rotate(b);
			}
			else
			{
				num = b->num[i];
				while (b->num[0] != num)
				{
					ft_putendl("rb");
					rotate(b);
				}
				ft_putendl("pa");
				push(a, b);
				i = -1;	
			}
			i++;
		}
	}
}

//tri de b
void 		sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = b->len;
	if (b->len > 0)
	{
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
			return ;
		}
		if (b->len == 1)
		{
			ft_putendl("pa");
			push(a, b);
			ft_putendl("ra");
			rotate(a);
			return ;
		}
		pivot = get_pivot(b);
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
}

//une sorte de quicksort? il met les plus petit dans b et les plus grands a la fin de a
static void	split_lower_n_higher(t_stack *a, t_stack *b, int pivot)
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

void		in_a(t_stack *a, t_stack *b, int pivot, int lower)
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

void		autre_tri(t_stack *a, t_stack *b, int pivot)
{
	int		num;
	int		lower;
	int		first;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	num = 0;
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
		pivot = get_pivot_sort(a, b);
		split_lower_n_higher(a, b, pivot);
		autre_tri(a, b, pivot);
	}
}

void 		quicksort(t_stack *a, t_stack *b)
{
	int		pivot;
	int		len;

	len = a->len;
	pivot = get_pivot(a);
	if (check_stack(a))
		return short_sort(a, b);
	while (len-- > 0)
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
	sort_b(a, b);
	autre_tri(a, b, pivot);
}
