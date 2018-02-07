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

#include "checker.h"

int			main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*b;
	int		ret;
	char	*op;

	a = new_pile(argc - 1);
	b = new_pile(argc - 1);
	b->len = 0;
	i = 0;
	while (++i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], a->num, i - 1))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		a->num[i - 1] = ft_atoi(argv[i]);
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
	pile_del(&a);
	pile_del(&b);
	return (0);
}
