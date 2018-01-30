/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/30 16:00:47 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void exchange(int *list, int x, int y, int len)
{
	int		temp;
	int		i;
	int		j;
	int		c;
	int		abs;

	abs = x - y;
	if ((x == 0 || x == 1) && (y == 0 || y == 1) && x != y)
		ft_putendl("sa");
	else if (ABS(x - y) > 0)
	{
		abs = ABS(abs);
		j = x < y ? x : y;
		i = 0;
		c = 0;
		while (i < j)
		{
			ft_putendl("pb");
			c++;
			i++;
		}
		i = 0;
		while (i < abs - 1)
		{
			ft_putendl("sa");
			ft_putendl("pb");
			c++;
			i++;
		}
		ft_putendl("sa");
		i = 0;
		while (i < c)
		{
			ft_putendl("pa");
			i++;
		}
	}
	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
	display(list, len);
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
		exchange(a->num, m, pivot, a->len);
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
				exchange(a->num, i, j, a->len);
			}
		}
		exchange(a->num, m, j, a->len);
		quicksort(a,m,j-1);
		quicksort(a,j+1,n);
	}
}

void	resolve(t_pile *a, t_pile *b)
{
	(void)b;
//	printf("Avant:\n");
//	display(a->num, a->len);
	quicksort(a, 0, a->len - 1);
//	printf("Apres:\n");
//	display(a->num, a->len);
}

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*b;
	char	**ops;

	if (argc > 2)
	{
		a = new_pile(argc - 1);
		b = new_pile(0);
		ops = 0;
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
		resolve(a, b);
	}
	return (0);
}
