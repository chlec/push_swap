/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/30 17:06:36 by clecalie         ###   ########.fr       */
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
	t_pile	*a;
	t_pile	*b;

	if (x != y)
	{
		a = new_pile(len);
		b = new_pile(0);
		i = -1;
		while (++i < len)
			a->num[i] = list[i];

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
			while (i < j)
			{
				ft_putendl("pb");
				push(b, a);
				c++;
				i++;
			}
			i = 0;
			while (i < abs - 1)
			{
				ft_putendl("sa");
				swap(a);
				ft_putendl("pb");
				push(b, a);
				c++;
				i++;
			}
			ft_putendl("sa");
			i = 0;
			while (i < c)
			{
				ft_putendl("pa");
				push(a, b);
	//			printf("a->len == %d, 0: %d, 1: %d\n", a->len, a->num[0], a->num[1]);
				if (a->len >= 2 && a->num[0] > a->num[1])
				{
					ft_putendl("sa");
					swap(a);
				}
				i++;
			}
			/*	if (list[x] > list[y])
				{
				ft_putendl("sa");
				swap(a);
				}*/
		}
		temp = list[x];
		list[x] = list[y];
		list[y] = temp;
		pile_del(&a);
		pile_del(&b);
	//	display(list, len);
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
