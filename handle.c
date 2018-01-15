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

int		handle_ops(char **ops, int *a, int len)
{
	int		i;
	int		b[len];
	char	*op;
	int		temp;
	int		a_len;
	int		b_len;
	int		j;

	a_len = len;
	b_len = 0;
	i = 0;
	while (ops[i])
	{
		op = ops[i];
		if (ft_strequ(op, "sa"))
		{
			temp = a[0];
			a[0] = a[1];
			a[1] = temp;
		}
		else if (ft_strequ(op, "sb"))
		{
			temp = b[0];
			b[0] = b[1];
			b[1] = temp;
		}
		else if (ft_strequ(op, "ss"))
		{
			temp = a[0];
			a[0] = a[1];
			a[1] = temp;
			temp = b[0];
			b[0] = b[1];
			b[1] = temp;
		}
		else if (ft_strequ(op, "pa") && b_len > 0)
		{
			j = a_len;
			while (j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[0] = b[0];
			j = 0;
			while (j < b_len)
			{
				b[j] = b[j + 1];
				j++;
			}
			a_len++;
			b_len--;
		}
		else if (ft_strequ(op, "pb") && a_len > 0)
		{
			j = b_len;
			while (j >= 0)
			{
				b[j + 1] = b[j];
				j--;
			}
			b[0] = a[0];
			j = 0;
			while (j < a_len)
			{
				a[j] = a[j + 1];
				j++;
			}
			b_len++;
			a_len--;
		}
		else if (ft_strequ(op, "ra"))
		{
			temp = a[0];
			j = 0;
			while (j + 1 < a_len)
			{
				a[j] = a[j + 1];
				j++;
			}
			a[j] = temp;
		}
		else if (ft_strequ(op, "rb"))
		{
			temp = b[0];
			j = 0;
			while (j + 1 < b_len)
			{
				b[j] = b[j + 1];
				j++;
			}
			b[j] = temp;
		}
		else if (ft_strequ(op, "rr"))
		{
			temp = a[0];
			j = 0;
			while (j + 1 < a_len)
			{
				a[j] = a[j + 1];
				j++;
			}
			a[j] = temp;
			temp = b[0];
			j = 0;
			while (j + 1 < b_len)
			{
				b[j] = b[j + 1];
				j++;
			}
			b[j] = temp;

		}
		else if (ft_strequ(op, "rra"))
		{
			temp = a[a_len - 1];
			j = a_len;
			while (j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[0] = temp;
		}
		else if (ft_strequ(op, "rrb"))
		{
			temp = b[b_len - 1];
			j = b_len;
			while (j >= 0)
			{
				b[j + 1] = b[j];
				j--;
			}
			b[0] = temp;
		}
		else if (ft_strequ(op, "rrr"))
		{
			temp = a[a_len - 1];
			j = a_len;
			while (j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[0] = temp;
			temp = b[b_len - 1];
			j = b_len;
			while (j >= 0)
			{
				b[j + 1] = b[j];
				j--;
			}
			b[0] = temp;
		}
		i++;
		j = 0;
		ft_strdel(&op);
	}
	free(ops);
	ops = 0;
	return (a_len);
}
