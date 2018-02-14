/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 13:47:32 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_number(char *str)
{
	(void)str;
}

static int	store_number(t_stack *a, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!valid_number(argv[i]) || !only_number(argv[i])
				|| has_double(argv[i], a->num, i - 1))
			return (0);
		a->num[i - 1] = ft_atoi(argv[i]);
	}
	return (1);
}

static int	get_and_exec_op(t_stack *a, t_stack *b)
{
	int		ret;
	char	*op;

	op = 0;
	while ((ret = get_next_line(0, &op)) > 0)
	{
		if (!valid_ops(op))
		{
			ft_putendl_fd("Error", 2);
			ft_strdel(&op);
			return (0);
		}
		a->len = handle_ops(op, a, b);
		ft_strdel(&op);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	b->len = 0;
	i = 0;
	if (!store_number(a, argc, argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (!(get_and_exec_op(a, b)))
		return (0);
	if (check_valid(a, b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_del(&a);
	stack_del(&b);
	return (0);
}
