/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/31 17:19:55 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void exchange(t_pile *a, int x, int y)
{
	int		i;
	int		j;
	int		c;
	int		abs;
	t_pile	*b;

	if (x != y)
	{
		b = new_pile(a->len);
		b->len = 0;
		abs = x - y;
		if ((x == 0 || x == 1) && (y == 0 || y == 1) && x != y)
		{
			ft_putendl("sa");
			swap(a);	
		}
		else if (ABS(x - y) > 0)
		{
			abs = ABS(abs);
			j = x < y ? x : y;
			i = 0;
			c = 0;
			if (a->num[a->len - 1] < a->num[a->len - 2])
			{
				ft_putendl("rra");
				rev_rotate(a);
			}
			while (i < j)
			{
				ft_putendl("pb");
				push(b, a);
				if (b->len >= 2 && b->num[0] < b->num[1])
				{
					ft_putendl("sb");
					swap(b);
				}
				c++;
				i++;
			}
			i = 0;
			while (i < abs - 1)
			{
				ft_putendl("sa");
				swap(a);
				if (a->len > 0)
				{
					ft_putendl("pb");
					push(b, a);
				}
				c++;
				i++;
			}
			if (a->len >= 2 && a->num[0] > a->num[1])
			{
				ft_putendl("sa");
				swap(a);
			}
			i = 0;
			while (i < c)
			{
				if (b->len > 0)
				{
					ft_putendl("pa");
					push(a, b);
				}
/*				if (a->len >= 2 && a->num[0] > a->num[1])
				{
					ft_putendl("sa");
					swap(a);
				}*/
				i++;
			}
		}
		if (b)
			pile_del(&b);
	}
}

void quicksort(t_pile *a, int m, int n)
{
	int		key;
	int		i;
	int		j;
	int		pivot;

	if (m < n)
	{
		pivot = (m + n) / 2;
		exchange(a, m, pivot);
		key = a->num[m];
		i = m + 1;
		j = n;
		while (i <= j)
		{
			while ((i <= n) && (a->num[i] <= key))
				i++;
			while ((j >= m) && (a->num[j] > key))
				j--;
			if (i < j)
			{
				exchange(a, i, j);
			}
		}
		exchange(a, m, j);
		quicksort(a,m,j-1);
		quicksort(a,j+1,n);
	}
}

void	resolve(t_pile *a)
{
	quicksort(a, 0, a->len - 1);
}

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*a;

	if (argc > 2)
	{
		a = new_pile(argc - 1);
		i = 1;
		while (i < argc)
		{
			if (!only_number(argv[i]) || has_double(argv[i], a->num, i - 1))
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			a->num[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		resolve(a);
		pile_del(&a);
	}
	return (0);
}
