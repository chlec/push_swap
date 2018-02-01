/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/01 11:36:37 by clecalie         ###   ########.fr       */
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
		printf("on change index x: %d et y: %d\n", x, y);
		b = new_pile(a->len);
		b->len = 0;
		//Si deja dqns l'ordre on retourne
		if (check_valid(a, b))
			return ;
		abs = x - y;
		//Si on doit echanger les 2 1er on le fait
		if ((x == 0 || x == 1) && (y == 0 || y == 1))
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
			//Si le dernier est plus petit que le 1er on decale la liste vers la droite
			if (a->num[a->len - 1] < a->num[a->len - 2])
			{
				ft_putendl("rra");
				rev_rotate(a);
			}
			while (i < j)
			{
				//On stock dans pb jusqu'a qu4on tombe sur le num a echanger
				ft_putendl("pb");
				push(b, a);
				//Si les 2 1ers sont dans le desordre de la pile b, on swap
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
				//On echange les 2 1ers puis on met ensuite le 1er dans b jusqu'a que les 2 chiffres sont cote a cote
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
			//Une fois colle, on les swap
			if (a->len >= 2 && a->num[0] > a->num[1])
			{
				ft_putendl("sa");
				swap(a);
			}
			i = 0;
			//Et on remet les elements de b dans a
			while (i < c)
			{
				if (b->len > 0)
				{
					ft_putendl("pa");
					push(a, b);
				}
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
