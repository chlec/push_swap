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

int		handle_ops(char **ops, t_pile *a)
{
	int		i;
	t_pile	*b;
	char	*op;

	b = new_pile(0);
	i = 0;
	while (ops[i])
	{
		op = ops[i];
		if (ft_strequ(op, "sa"))
			swap(a);
		else if (ft_strequ(op, "sb"))
			swap(b);
		else if (ft_strequ(op, "ss"))
		{
			swap(a);
			swap(b);
		}
		else if (ft_strequ(op, "pa") && b->len > 0)
			push(a, b);
		else if (ft_strequ(op, "pb") && a->len > 0)
			push(b, a);
		else if (ft_strequ(op, "ra"))
			rotate(a);
		else if (ft_strequ(op, "rb"))
			rotate(b);
		else if (ft_strequ(op, "rr"))
		{
			rotate(a);
			rotate(b);
		}
		else if (ft_strequ(op, "rra"))
			rev_rotate(a);
		else if (ft_strequ(op, "rrb"))
			rev_rotate(b);
		else if (ft_strequ(op, "rrr"))
		{
			rev_rotate(a);
			rev_rotate(b);
		}
		i++;
		ft_strdel(&op);
	}
	free(ops);
	ops = 0;
	return (a->len);
}
