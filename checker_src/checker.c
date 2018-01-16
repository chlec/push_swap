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

static void	check_valid(t_pile *a, t_pile *b)
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
	t_pile	*a;
	t_pile	*b;
	char	**ops;

	a = new_pile(argc - 1);
	b = new_pile(0);
	i = 1;
	while (i < argc)
	{
		if (!only_number(argv[i]) || has_double(argv[i], a, i - 1))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		a->num[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ops = store_args();
	a->len = handle_ops(ops, a, b);
	check_valid(a, b);
	return (0);
}
