/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/07 13:04:47 by clecalie         ###   ########.fr       */
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
		left = !(pile->len % 2);
		right = 0;
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

void 		quicksort(t_pile *a, t_pile *b, int start, int end)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = a->len;
	pivot = get_pivot(a);
	printf("le pivot vaut %d\n", pivot);
	while (i < a->len)
	{
		if (a->num[i] < pivot)
		{
			ft_putendl("pb");
			push(b, a);
			i = -1;
		}
		else// (a->num[i] > pivot)
		{
			ft_putendl("ra");
			rotate(a);
		}
		i++;
	}
	display(a->num, a->len);
}
