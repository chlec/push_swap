/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/15 15:17:22 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*add_end(char *str, char *add)
{
	char	*ret;

	if (!str || !add)
		return (0);
	if (!(ret = ft_strnew(ft_strlen(str) + ft_strlen(add) + 1)))
		return (0);
	ft_strcat(ret, str);
	ft_strcat(ret, add);
	return (ret);
}

int		only_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		has_double(char *str, int *num, int len)
{
	int		nb;
	int		i;

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

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	char	*all_op;
	int		i;
	int		num[argc - 1];
	char	**ops;

	i = 1;
	while (i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], num, i - 1))
		{
			ft_putendl("Error");
			return (0);
		}
		num[i - 1] = ft_atoi(argv[i]);	
		i++;
	}
	all_op = "";
	while ((ret = get_next_line(0, &line)) > 0)
	{
		all_op = add_end(all_op, line);
		all_op = add_end(all_op, "\n");
	}
	ops = ft_strsplit(all_op, '\n');
	argc = handle_ops(ops, num, i - 1);
	i = 0;
	while (i < argc)
		printf("%d\n", num[i++]);
	return (0);
}
