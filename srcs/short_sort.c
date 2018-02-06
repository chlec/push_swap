/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/01 11:21:00 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	short_sort(t_pile *a, t_pile *b)
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
		else if (check_stack(a) == 1 && b->num[0] < a->num[0])
		{
			ft_putendl("pa");
			push(a, b);	
		}
		else if ((a->num[0] < a->num[1]) && (b->len == 0 || a->num[0] >b->num[0]))
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
	/*int		i;
	int		c;
	int		temp;

	if (a->len > 1 && !check_valid(a, b))
	{
		if (a->num[0] > a->num[1])
		{
			ft_putendl("sa");
			swap(a);
			if (check_valid(a, b))
				return ;
		}
		i = a->len - 1;
		//Si i est supérier a a->len / 2 arrondi au dessus (Ex 5 / 2 vaut 3)
		while (i > 0 && i > a->len / 2 + a->len % 2)
		{
			//Ex 3 2 1 0        -> Si 0 est < a 1, on rra 2 fois
			if (a->num[i] < a->num[i - 1])
			{
				temp = a->num[i - 1];
				c = 0;
				while (a->num[0] != temp)
				{
					ft_putendl("rra");
					rev_rotate(a);
					if (check_valid(a, b))
						return ;
					c++;
				}
				ft_putendl("sa");
				swap(a);
				if (check_valid(a, b))
					return ;
				while (c > 0)
				{
					ft_putendl("ra");
					rotate(a);
					if (check_valid(a, b))
						return ;
					c--;
				}
				short_sort(a, b);
				return ;
			}
			i--;
		}
		i = 0;
		while (i < a->len - 1)
		{
			if (a->num[i] > a->num[i + 1])
			{
				c = 0;
				while (c < i)
				{
					ft_putendl("pb");
					push(b, a);
					c++;
				}
				ft_putendl("sa");
				swap(a);
				while (c > 0)
				{
					ft_putendl("pa");
					push(a, b);
					c--;
				}
				short_sort(a, b);
				return ;
			}
			i++;
		}
	}*/
}