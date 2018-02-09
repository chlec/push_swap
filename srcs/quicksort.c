/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:59:47 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 16:59:08 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int			lowest_num(t_pile *a, t_pile *b)
{
	int		best;
	int		i;

	best = a->num[0];
	i = 0;
	while (i < b->len)
	{
		if (b->num[i] < best)
			best = b->num[i];
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		if (a->num[i] < best)
			best = a->num[i];
		i++;
	}
	return (best);
}

int		get_pivot_sort(t_pile *a, t_pile *b)
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

int		get_pivot(t_pile *a)
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

void		quick3(t_pile *a, t_pile *b)
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

void 		quick4(t_pile *a, t_pile *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = b->len;
	pivot = get_pivot(b);
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
			a->sorted++;
			return ;
		}
		if (b->len == 1)
		{
			ft_putendl("pa");
			push(a, b);
			ft_putendl("ra");
			rotate(a);
			a->sorted++;
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
		quick4(a, b);
	}
}
void		tri_3(t_pile *a, t_pile *b, int pivot)
{
	int		i;
	int		first;
	int		on_right;

	i = 0;
	first = lowest_num(a, b);
	on_right = 0;
	while (a->num[0] != first)
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
		if (b->num[0] > pivot)
		{
			ft_putendl("rb");
			rotate(b);
		}
	}
	while (on_right > 0)
	{
		ft_putendl("rra");
		rev_rotate(a);
		on_right--;

	}
	quick4(a, b);
}


void		autre_tri(t_pile *a, t_pile *b, int pivot)
{
	int		i;
	int		j;
	int		num;
	int		lower;
	int		first;
	int		on_right;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	num = 0;
	on_right = 0;
	first = lowest_num(a, b);
	while (a->num[a->len - 1] != pivot)
	{
		lower = a->num[0] != first ? a->num[0] : higher(a, b);
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
			if (a->num[i] < lower && a->num[i] != first)
				lower = a->num[i];
			i++;
		}
		/*ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);
		printf("le plus lower: %d, pivot: %d\n", lower, pivot);
		usleep(30000);*/
		/*
		 * 	ON MET L'ELEMENT EN 1ER POSITION DE A - PILE A
		 */
		if (is_in_stack(a, lower))
		{
			while (a->num[0] != lower)// && a->num[1] != lower)
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
					ft_putendl("rra");
					rev_rotate(a);
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
		else
		{
			/*
			 * ON MET L'ELEMENT EN 1ER POSITION DE A - PILE B
			 */ 
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
				if (b->num[1] == lower)
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
				else
				{
					while (b->num[0] != lower)
					{
						ft_putendl("rrb");
						rev_rotate(b);
					}
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
		tri_3(a, b, pivot);
		autre_tri(a, b, pivot);
	}
}
//le but est de prendre le pivot de b, et de mettre tout les plus gros sur a et les plus petits les laisser

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
		autre_tri(a, b, get_pivot_sort(a, b));
		//short_sort(a, b);
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
		if (a->num[0] <= pivot)
		{
			ft_putendl("pb");
			push(b, a);
		}
		else
		{
			if (b->len >= 2 && b->num[0] < b->num[1])
			{
				ft_putendl("rr");
				rotate(b);
				rotate(a);
			}
			else
			{
				ft_putendl("ra");
				rotate(a);
			}
		}
		i++;
	}
	quick2(a, b);
}
