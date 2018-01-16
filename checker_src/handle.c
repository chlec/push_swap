/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:19:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/15 17:02:56 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_swap(t_pile *a, t_pile *b, char *op)
{
	if (ft_strequ(op, "sa"))
	{
		swap(a);
		return (1);
	}
	else if (ft_strequ(op, "sb"))
	{
		swap(b);
		return (1);
	}
	else if (ft_strequ(op, "ss"))
	{
		swap(a);
		swap(b);
		return (1);
	}
	return (0);
}
static int	check_push(t_pile *a, t_pile *b, char *op)
{
	if (ft_strequ(op, "pa") && b->len > 0)
	{
		push(a, b);
		return (1);
	}
	else if (ft_strequ(op, "pb") && a->len > 0)
	{
		push(b, a);
		return (1);
	}
	return (0);
}

static int	check_rotate(t_pile *a, t_pile *b, char *op)
{
	if (ft_strequ(op, "ra"))
	{
		rotate(a);
		return (1);
	}
	else if (ft_strequ(op, "rb"))
	{
		rotate(b);
		return (1);
	}
	else if (ft_strequ(op, "rr"))
	{
		rotate(a);
		rotate(b);
		return (1);
	}
	return (0);
}

static int	check_rev_rotate(t_pile *a, t_pile *b, char *op)
{
	if (ft_strequ(op, "rra"))
	{
		rev_rotate(a);
		return (1);
	}
	else if (ft_strequ(op, "rrb"))
	{
		rev_rotate(b);
		return (1);
	}
	else if (ft_strequ(op, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
		return (1);
	}
	return (0);
}

int		handle_ops(char **ops, t_pile *a, t_pile *b)
{
	int		i;
	char	*op;

	i = 0;
	while (ops[i])
	{
		op = ops[i];
		if (!(check_swap(a, b, op)))
			if (!(check_push(a, b, op)))
				if (!check_rotate(a, b, op))
					check_rev_rotate(a, b, op);
		ft_strdel(&op);
		i++;
	}
	free(ops);
	ops = 0;
	return (a->len);
}