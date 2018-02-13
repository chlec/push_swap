/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/07 14:35:28 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	store_number(t_stack *a, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], a->num, i - 1))
			return (0);
		a->num[i - 1] = ft_atoi(argv[i]);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		ret;
	char	*op;

	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	b->len = 0;
	i = 0;
	if (!store_number(a, argc, argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	while ((ret = get_next_line(0, &op)) > 0)
	{
		if (!valid_ops(op))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		a->len = handle_ops(op, a, b);
	}
	if (check_valid(a, b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_del(&a);
	stack_del(&b);
	return (0);
}
