/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/15 16:26:29 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_stack *a, t_stack *b)
{
	if (a->len >= 12)
		quicksort(a, b);
	else
		short_sort(a, b);
	stack_del(&a);
	stack_del(&b);
}

int		main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc > 2)
	{
		a = new_stack(argc - 1);
		b = new_stack(argc - 1);
		b->len = 0;
		i = 0;
		while (++i < argc)
		{
			if (!valid_number(argv[i]) ||
					!only_number(argv[i]) || has_double(argv[i], a->num, i - 1))
			{
				ft_putendl_fd("Error", 2);
				stack_del(&a);
				stack_del(&b);
				return (0);
			}
			a->num[i - 1] = ft_atoi(argv[i]);
		}
		resolve(a, b);
	}
	return (0);
}
