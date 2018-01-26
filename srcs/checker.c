/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/17 11:32:05 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*add_end(char *str, char *add)
{
	char	*ret;

	if (!str || !add)
		return (0);
	if (!(ret = ft_strnew(ft_strlen(str) + ft_strlen(add))))
		return (0);
	ft_strcpy(ret, str);
	ft_strcat(ret, add);
	ft_strdel(&str);
	ft_strdel(&add);
	return (ret);
}

static char	**store_args(void)
{
	char	*line;
	char	*all_op;
	int		ret;
	char	**ops;

	all_op = ft_strnew(0);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		all_op = add_end(all_op, ft_strdup(line));
		all_op = add_end(all_op, ft_strdup("\n"));
		ft_strdel(&line);
	}
	ops = ft_strsplit(all_op, '\n');
	ft_strdel(&all_op);
	return (ops);
}

int			main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*b;
	char	**ops;

	a = new_pile(argc - 1);
	b = new_pile(0);
	i = 0;
	while (++i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], a, i - 1))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		a->num[i - 1] = ft_atoi(argv[i]);
	}
	if (!valid_ops((ops = store_args())))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	a->len = handle_ops(ops, a, b);
	check_valid(a, b);
	while (1);
	return (0);
}
