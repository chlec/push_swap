/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/01 15:06:39 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	tri_facile(t_pile *a, t_pile *b)
{
	int		i;
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
		while (i > 0 && i >= a->len / 2)
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
				tri_facile(a, b);
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
				tri_facile(a, b);
				return ;
			}
			i++;
		}
	}
}

void	exchange(t_pile *a, t_pile *b, int x, int y)
{
	int		i;
	int		j;
	int		c;
	int		abs;
	int		temp;

	if (x != y)
	{
		//printf("on change index x: %d et y: %d\n", x, y);
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
			/*	if (a->num[a->len - 1] < a->num[a->len - 2])
				{
				ft_putendl("rra");
				rev_rotate(a);
				}*/
			//On stock dans pb jusqu'a qu4on tombe sur le num a echanger
			//Si j > a->len / 2 ---> rra
			if (j > a->len / 2)
			{
				temp = a->num[j];
				while (a->num[0] != temp)
				{
					ft_putendl("rra");
					rev_rotate(a);
					c++;
				}
			}
			else
			{
				while (i < j)
				{
					ft_putendl("pb");
					push(b, a);
					c++;
					i++;
				}
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
			if (b->len > 0)
			{
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
			else
			{
				while (i < c)
				{
					ft_putendl("ra");
					rotate(a);
					i++;
				}
			}
		}
	}
}

void quicksort(t_pile *a, t_pile *b,  int m, int n)
{
	int		key;
	int		i;
	int		j;
	int		pivot;

	if (m < n)
	{
		pivot = (m + n) / 2;
		exchange(a, b, m, pivot);
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
				exchange(a, b, i, j);
			}
		}
		exchange(a, b, m, j);
		quicksort(a, b, m, j - 1);
		quicksort(a, b, j + 1, n);
	}
}

void	resolve(t_pile *a, t_pile *b)
{
	if (a->len > 20)
		quicksort(a, b, 0, a->len - 1);
	else
		tri_facile(a, b);
}

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*b;

	if (argc > 2)
	{
		a = new_pile(argc - 1);
		b = new_pile(argc - 1);
		b->len = 0;
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
		pile_del(&a);
		pile_del(&b);
	}
	return (0);
}
