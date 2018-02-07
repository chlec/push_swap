/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/07 17:52:10 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static void	exchange(t_pile *a, t_pile *b, int x, int y)
{
	int		i;
	int		little;
	int		c;
	int		diff;
	int		temp;
	//display(a->num, a->len);
	dprintf(2, "on echange a->num[%d]=%d avec a->num[%d]=%d\n", x, a->num[x], y, a->num[y]);
	//temp = a->num[x];
	//a->num[x] = a->num[y];
	//a->num[y] = temp;
	if (x != y)
	{
		//Si deja dqns l'ordre on retourne
		if (check_valid(a, b))
			return ;
		//diff -> diffenrence entre les deux en val abs
		diff = x - y;
		diff = ABS(diff);
		little = x < y ? x : y;
		//Si on doit echanger les 2 1er on le fait
		if ((x == 0 || x == 1) && (y == 0 || y == 1))
		{
			ft_putendl("sa");
			swap(a);
		}
		else if (diff > 0)
		{
			if (diff > a->len / 2 - 1)
			{
				//go pb and go rra
				c = 0;
				while (c < little)
				{
					ft_putendl("pb");
					push(b, a);
					c++;
				}
				temp = a->num[x > y ? x : y];
				i = 0;
				while (a->num[0] != temp)
				{
					ft_putendl("rra");
					rev_rotate(a);
					i++;
					if (a->num[0] != temp && a->len > 0)
					{
						ft_putendl("pb");
						push(b, a);
					}
				}
				ft_putendl("sa");
				swap(a);
				while(i > 0)
				{
					ft_putendl("ra");
					rotate(a);
					if (b->len > 0)
					{
						ft_putendl("pa");
						push(a, b);
					}
					i--;
				}
				while (c > 0 && b->len > 0)
				{
					ft_putendl("pa");
					push(a, b);
					c--;
				}
			}
			else
			{
				c = 0;
				while (c < little)
				{
					ft_putendl("pb");
					push(b, a);
					c++;
				}
				i = 1;
				while (i < diff)
				{
					ft_putendl("sa");
					swap(a);
					ft_putendl("pb");
					push(b, a);
					i++;
				}
				ft_putendl("sa");
				swap(a);
				while (i > 1)
				{
					ft_putendl("pa");
					push(a, b);
					ft_putendl("sa");
					swap(a);
					i--;
				}
				while (c > 0)
				{
					ft_putendl("pa");
					push(a, b);
					c--;
				}
			}
		}
	}
}

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

void		autre_tri(t_pile *a, t_pile *b)
{
	int		i;
	int		j;
	int		num;
	int		temp;
	int		lower;
	int		pivot;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	num = 0;
	pivot = get_pivot(a);
	while (a->num[a->len - 1] != pivot)
	{
		temp = 0;
		lower = a->num[0];
		//	usleep(300000);
	/*	ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);*/
		i = 0;
		while (i < a->len)
		{
			if (a->num[i] < lower && a->num[i] > num)
			{
				lower = a->num[i];
				temp = 1;
			}
			i++;
		}
		while (temp == 1 && a->num[0] != lower)
		{
			ft_putendl("pb");
			push(b, a);
		}
		j = 0;
		temp = 0;
		while (j < b->len)
		{
			if (b->num[j] < lower && b->num[j] > num)
			{
				temp = 1;
				lower = b->num[j];
			}
			j++;

		}
		if (temp == 1)
		{
			while (b->num[0] != lower)
			{
				ft_putendl("rb");
				rotate(b);
			}
			ft_putendl("pa");
			push(a, b);
		}
		while (a->num[a->len - 1] != lower)
		{
			ft_putendl("ra");
			rotate(a);
		}
		num = lower;
	}
	while (b->len > 0)
	{
		ft_putendl("pa");
		push(a, b);
	}
	/*ft_putstr("a: \t");
	display(a->num, a->len);
	ft_putstr("b: \t");
	display(b->num, b->len);*/

}

void 		quick2(t_pile *a, t_pile *b, int start, int end)
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
		autre_tri(a, b);
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
	quick2(a, b, 0, 0);
}

void 		quicksort(t_pile *a, t_pile *b, int start, int end)
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
	quick2(a, b, 0, 0);
}
