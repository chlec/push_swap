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
	int		temp;
	int		j;

	b = new_pile(0);
	i = 0;
	while (ops[i])
	{
		op = ops[i];
		if (ft_strequ(op, "sa"))
		{
			temp = a->num[0];
			a->num[0] = a->num[1];
			a->num[1] = temp;
		}
		else if (ft_strequ(op, "sb"))
		{
			temp = b->num[0];
			b->num[0] = b->num[1];
			b->num[1] = temp;
		}
		else if (ft_strequ(op, "ss"))
		{
			temp = a->num[0];
			a->num[0] = a->num[1];
			a->num[1] = temp;
			temp = b->num[0];
			b->num[0] = b->num[1];
			b->num[1] = temp;
		}
		else if (ft_strequ(op, "pa") && b->len > 0)
		{
			j = a->len;
			while (j >= 0)
			{
				a->num[j + 1] = a->num[j];
				j--;
			}
			a->num[0] = b->num[0];
			j = 0;
			while (j < b->len)
			{
				b->num[j] = b->num[j + 1];
				j++;
			}
			a->len++;
			b->len--;
		}
		else if (ft_strequ(op, "pb") && a->len > 0)
		{
			j = b->len;
			while (j >= 0)
			{
				b->num[j + 1] = b->num[j];
				j--;
			}
			b->num[0] = a->num[0];
			j = 0;
			while (j < a->len)
			{
				a->num[j] = a->num[j + 1];
				j++;
			}
			b->len++;
			a->len--;
		}
		else if (ft_strequ(op, "ra"))
		{
			temp = a->num[0];
			j = 0;
			while (j + 1 < a->len)
			{
				a->num[j] = a->num[j + 1];
				j++;
			}
			a->num[j] = temp;
		}
		else if (ft_strequ(op, "rb"))
		{
			temp = b->num[0];
			j = 0;
			while (j + 1 < b->len)
			{
				b->num[j] = b->num[j + 1];
				j++;
			}
			b->num[j] = temp;
		}
		else if (ft_strequ(op, "rr"))
		{
			temp = a->num[0];
			j = 0;
			while (j + 1 < a->len)
			{
				a->num[j] = a->num[j + 1];
				j++;
			}
			a->num[j] = temp;
			temp = b->num[0];
			j = 0;
			while (j + 1 < b->len)
			{
				b->num[j] = b->num[j + 1];
				j++;
			}
			b->num[j] = temp;

		}
		else if (ft_strequ(op, "rra"))
		{
			temp = a->num[a->len - 1];
			j = a->len;
			while (j >= 0)
			{
				a->num[j + 1] = a->num[j];
				j--;
			}
			a->num[0] = temp;
		}
		else if (ft_strequ(op, "rrb"))
		{
			temp = b->num[b->len - 1];
			j = b->len;
			while (j >= 0)
			{
				b->num[j + 1] = b->num[j];
				j--;
			}
			b->num[0] = temp;
		}
		else if (ft_strequ(op, "rrr"))
		{
			temp = a->num[a->len - 1];
			j = a->len;
			while (j >= 0)
			{
				a->num[j + 1] = a->num[j];
				j--;
			}
			a->num[0] = temp;
			temp = b->num[b->len - 1];
			j = b->len;
			while (j >= 0)
			{
				b->num[j + 1] = b->num[j];
				j--;
			}
			b->num[0] = temp;
		}
		i++;
		j = 0;
		ft_strdel(&op);
	}
	free(ops);
	ops = 0;
	return (a->len);
}
