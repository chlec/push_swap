/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/08 16:17:35 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	resolve(t_pile *a, t_pile *b)
{
	if (a->len >= 12)
		quicksort(a, b);
	else
		short_sort(a, b);
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
