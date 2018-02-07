/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/07 17:52:10 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int		get_pivot(t_pile *pile)
{
	int		i;
	int		j;
	int		pivot;
	int		left;
	int		right;

	i = 0;
	left = 0;
	right = 1;
	while (i < pile->len && left != right)
	{
		right = !(pile->len % 2);
		left = 0;
		pivot = pile->num[i];
		j = 0;
		while (j < pile->len)
		{
			if (pivot < pile->num[j])
				right++;
			if (pivot > pile->num[j])
				left++;
			j++;
		}
		i++;
	}
	return (pivot);
}

/*int			lower_stack(t_pile *a)
{
	int		i;
	int		lower;

	lower = a->len[0];
	i = 0;
	while (i < a->len)
	{
		if (a->num[i] < lower && a->num[i] > num)
		{
			lower = a->num[i];
		}
		i++;
	}
}*/

int			is_in_stack(t_pile *pile, int num)
{
	int 	i;

	i = 0;
	while (i < pile->len)
	{
		if (pile->num[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void		autre_tri(t_pile *a, t_pile *b)
{
	int		i;
	int		j;
	int		num;
	int		lower;
	int		pivot;
	int		first;

	//En gros on prend le 1er nombre, si on trouve plus petit on le met dans b et on refait
	//Sinon on le met a la fin
	num = 0;
	pivot = get_pivot(a);
	first = a->num[0];
	ft_putendl("ra");
	rotate(a);
	while (a->num[a->len - 1] != pivot)
	{
		lower = a->num[0];
		ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);
		j = 0;
		while (j < b->len)
		{
			if (b->num[j] < lower)
			{
				lower = b->num[j];
			}
			j++;
		}
		i = 0;
		while (i < a->len && a->num[i] != first)
		{
			if (a->num[i] < lower)
			{
				lower = a->num[i];
			}
			i++;
		}
		printf("le lower is %d\n", lower);
		if (is_in_stack(a, lower))
		{
			while (a->num[0] != lower)
			{
				ft_putendl("pb");
				push(b, a);
			}
		}
		else if (is_in_stack(b, lower))
		{
			while (b->num[0] != lower)
			{
				ft_putendl("rb");
				rotate(b);
			}
			ft_putendl("pa");
			push(a, b);
		}
		while (a->num[a->len - 1] != lower)
		{
			ft_putendl("ra");
			rotate(a);
			sleep(1);
		/*	ft_putstr("a: \t");
		display(a->num, a->len);
		ft_putstr("b: \t");
		display(b->num, b->len);*/
		}
	}
	while (b->len > 0)
	{
		ft_putendl("pa");
		push(a, b);
	}
	/*ft_putstr("a: \t");
	display(a->num, a->len);
	ft_putstr("b: \t");
	display(b->num, b->len);*/

}

void 		quick2(t_pile *a, t_pile *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = b->len;
	pivot = get_pivot(b);
	if (b->len == 2)
	{
		if (b->num[0] < b->num[1])
		{
			ft_putendl("sb");
			swap(b);
		}
		ft_putendl("pa");
		push(a, b);
		ft_putendl("pa");
		push(a, b);
		autre_tri(a, b);
		//		short_sort(a, b);
		return ;
	}
	while (i < len)
	{
		if (b->num[0] > pivot)
		{
			ft_putendl("pa");
			push(a, b);
		}
		else
		{
			ft_putendl("rb");
			rotate(b);
		}
		i++;
	}
	quick2(a, b);
}

void 		quicksort(t_pile *a, t_pile *b)
{
	int		pivot;
	int		i;
	int		len;

	i = 0;
	len = a->len;
	pivot = get_pivot(a);
	if (check_stack(a))
	{
		short_sort(a, b);
		return ;
	}
	while (i < len)
	{
		if (a->num[0] < pivot)
		{
			ft_putendl("pb");
			push(b, a);
		}
		else
		{
			ft_putendl("ra");
			rotate(a);
		}
		i++;
	}
	quick2(a, b);
}
