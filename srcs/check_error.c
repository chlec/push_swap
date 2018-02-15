/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:45:04 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/15 16:33:53 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		only_number(char *str)
{
	int		nb;
	char	*str_nbr;
	int		i;

	i = 0;
	nb = ft_atoi(str);
	str_nbr = ft_itoa(nb);
	while ((str[i] == '0' || str[i] == '+') && str[i + 1])
		i++;
	if (str[i] == str_nbr[0])
	{
		ft_strdel(&str_nbr);
		return (1);
	}
	ft_strdel(&str_nbr);
	return (0);
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

int		valid_number(char *str)
{
	if ((ft_atoi(str) > 0 && str[0] == '-')
			|| (ft_atoi(str) < 0 && str[0] != '-'))
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
