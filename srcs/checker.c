/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/19 13:46:53 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_ops(char *op)
{
	if (!ft_strequ(op, "sa") &&
			!ft_strequ(op, "sb") &&
			!ft_strequ(op, "ss") &&
			!ft_strequ(op, "pa") &&
			!ft_strequ(op, "pb") &&
			!ft_strequ(op, "ra") &&
			!ft_strequ(op, "rb") &&
			!ft_strequ(op, "rr") &&
			!ft_strequ(op, "rra") &&
			!ft_strequ(op, "rrb") &&
			!ft_strequ(op, "rrr"))
		return (0);
	return (1);
}

static int	store_number(t_stack *a, int argc, char **argv, int start)
{
	int		i;

	i = start;
	while (i < argc)
	{
		if (!valid_number(argv[i]) ||
				!only_number(argv[i]) ||
				has_double(argv[i], a->num, i - start))
			return (0);
		a->num[i - start] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

static void	handle_bonus(char **argv, char *op, t_stack *a, t_stack *b)
{
	if (argv[1][0] == '-' && ft_strchr(argv[1], 'o'))
	{
		ft_putstr("Operator: ");
		ft_putendl(op);
	}
	if (argv[1][0] == '-' && ft_strchr(argv[1], 'v'))
	{
		ft_putstr("Stack A: \t");
		display(a->num, a->len, '6');
		ft_putstr("Stack B: \t");
		display(b->num, b->len, '2');
		ft_putendl("-----------------------");
	}
}

static int	get_and_exec_op(t_stack *a, t_stack *b, char **argv)
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
			stack_del(&a);
			stack_del(&b);
			return (0);
		}
		a->len = handle_ops(op, a, b);
		handle_bonus(argv, op, a, b);
		ft_strdel(&op);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	if (argv[1][0] == '-' && (ft_strchr(argv[1], 'v') || ft_strchr(argv[1], 'o')))
		i = 2;
	a = new_stack(argc - i);
	b = new_stack(argc - i);
	b->len = 0;
	if (!store_number(a, argc, argv, i))
	{
		ft_putendl_fd("Error", 2);
		stack_del(&a);
		stack_del(&b);
		return (0);
	}
	if (!(get_and_exec_op(a, b, argv)))
		return (0);
	if (check_valid(a, b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_del(&a);
	stack_del(&b);
	return (0);
}
