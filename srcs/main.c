/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/29 14:28:32 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void exchange(int *list, int x, int y)
{
	int		temp;
	int		i;
	int		j;
	int		c;
	int		abs;

	abs = 0;
	if ((x == 0 || x == 1) && (y == 0 || y == 1) && x != y)
		ft_putendl("sa");
	else if ((abs = ABS(x - y)) > 0)
	{
		j = x < y ? x : y;
		i = 0;
		c = 0;
		while (i < j)
		{
			ft_putendl("rb");
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
			ft_putendl("ra");
			i++;
		}
	}
	printf("abs vaut: %d\n", abs);
	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}

int choose_pivot(int i, int j)
{
	return ((i+j) /2);
}

void quicksort(int *list, int m, int n)
{
	int key;
	int i;
	int j;
	int	k;

	printf("Quicksort function called with params %d and %d\n", m, n);
	if( m < n)
	{
		k = choose_pivot(m,n);
		printf("On echange index m: %d (contenu %d) avec index k: %d (contenu %d)\n", m, list[m], k, list[k]);
		exchange(list, m, k);
		key = list[m];
		i = m + 1;
		j = n;
		while(i <= j)
		{
			while((i <= n) && (list[i] <= key))
				i++;
			while((j >= m) && (list[j] > key))
				j--;
			if(i < j)
			{
				printf("On echange index i: %d (contenu %d) avec index j: %d (contenu %d)\n", i, list[i], j, list[j]);
				exchange(list, i, j);
			}
		}
		/* swap two elements */
		printf("On echange index m: %d (contenu %d) avec index j: %d (contenu %d)\n", m, list[m], j, list[j]);
		exchange(list, m, j);

		/* recursively sort the lesser list */
		quicksort(list,m,j-1);
		quicksort(list,j+1,n);
	}
}
void display(int *list, const int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d\t",list[i]);
	printf("\n");
}

void	resolve(t_pile *a, t_pile *b)
{
	(void)b;
	printf("Avant:\n");
	display(a->num, a->len);
	quicksort(a->num, 0, a->len - 1);
	printf("Apres:\n");
	display(a->num, a->len);
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
