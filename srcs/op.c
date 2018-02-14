/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:19:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/14 12:00:33 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push first element of b to a
*/

void	push(t_stack *a, t_stack *b)
{
	int		j;

	j = a->len - 1;
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

/*
** Move every elements to the bottoem. the last become the first
*/

void	rev_rotate(t_stack *stack)
{
	int		temp;
	int		j;

	temp = stack->num[stack->len - 1];
	j = stack->len - 2;
	while (j >= 0)
	{
		stack->num[j + 1] = stack->num[j];
		j--;
	}
	stack->num[0] = temp;
}

/*
** Move every elements to the top. the first become the last
*/

void	rotate(t_stack *stack)
{
	int		j;
	int		temp;

	temp = stack->num[0];
	j = 0;
	while (j + 1 < stack->len)
	{
		stack->num[j] = stack->num[j + 1];
		j++;
	}
	stack->num[j] = temp;
}

/*
** Swap the two first elements of a stack
*/

void	swap(t_stack *stack)
{
	int		temp;

	temp = stack->num[0];
	stack->num[0] = stack->num[1];
	stack->num[1] = temp;
}
