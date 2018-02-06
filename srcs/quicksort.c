/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/01 11:21:00 by clecalie         ###   ########.fr       */
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
					if (a->num[0] != temp)
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
					ft_putendl("pa");
					push(a, b);
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

void 		quicksort(t_pile *a, t_pile *b,  int start, int end)
{
	int		pivot;
	int		left;
	int		right;

	left = start - 1;
	right = end + 1;
	pivot = a->num[start];
	if (start >= end)
		return ;
	while (1)
	{
		right--;
		while (a->num[right] > pivot)
			right--;
		left++;
		while (a->num[left] < pivot)
			left++;
		if (left < right)
			exchange(a, b, left, right);
		else
			break ;
	}
	//on traite la partie de gauche
	quicksort(a, b, start, right);
	//on traite la partir de droite
    quicksort(a, b, right+1, end);
}