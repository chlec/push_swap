/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:45:04 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/07 14:34:16 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		only_number(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int		has_double(char *str, int *num, int len)
{
	int		nb;
	int		i;

	if (!str)
		return (1);
	nb = ft_atoi(str);
	i = 0;
	while (i < len)
	{
		if (num[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int		valid_ops(char *op)
{
	//sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
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

int		check_valid(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (b->len > 0 || (a->num[i] > a->num[i + 1] && i < a->len - 1))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_stack(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->num[i] > stack->num[i + 1] && i < stack->len - 1)
			return (0);
		i++;
	}
	return (1);
}
