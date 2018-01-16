/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:45:04 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/16 11:45:31 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		only_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int		has_double(char *str, t_pile *pile, int len)
{
	int		nb;
	int		i;

	nb = ft_atoi(str);
	i = 0;
	while (i < len)
	{
		if (pile->num[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int		valid_ops(char **ops)
{
	int		i;

	i = 0;
	while (ops[i])
	{
		//sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
		i++;
	}
	return (1);
}

void	check_valid(t_pile *a, t_pile *b)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (b->len > 0 || (a->num[i] > a->num[i + 1] && i < a->len - 1))
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}
