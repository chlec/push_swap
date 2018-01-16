/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/16 11:49:02 by clecalie         ###   ########.fr       */
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
	ft_strcat(ret, str);
	ft_strcat(ret, add);
	ft_strdel(&str);
	return (ret);
}

static void	check_order(int *num, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (num[i] > num[i + 1] && i < len - 1)
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
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
		all_op = add_end(all_op, line);
		all_op = add_end(all_op, "\n");
		ft_strdel(&line);
	}
	ops = ft_strsplit(all_op, '\n');
	ft_strdel(&all_op);
	return (ops);
}

int			main(int argc, char **argv)
{
	int		i;
	int		num[argc - 1];
	char	**ops;

	i = 1;
	while (i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], num, i - 1))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		num[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ops = store_args();
	argc = handle_ops(ops, num, i - 1);
	check_order(num, argc);
	return (0);
}
