/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:54:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/15 16:39:48 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int len)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		exit(0);
	stack->len = len;
	if (len > 0)
	{
		if (!(stack->num = (int*)malloc(sizeof(int) * len)))
			exit(0);
	}
	else
		stack->num = 0;
	stack->sorted = 0;
	return (stack);
}

void	stack_del(t_stack **stack)
{
	if (*stack)
	{
		free((*stack)->num);
		(*stack)->num = 0;
		free(*stack);
		*stack = 0;
	}
}

void	display(int *list, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(list[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
