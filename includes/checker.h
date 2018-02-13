/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/09 17:39:12 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_stack
{
	int		*num;
	int		len;
	int		sorted;
}				t_stack;

int				handle_ops(char *op, t_stack *a, t_stack *b);
int				only_number(char *str);
int				has_double(char *str, int *num, int len);
t_stack			*new_stack(int len);
void			swap(t_stack *stack);
void			push(t_stack *a, t_stack *b);
void			rotate(t_stack *stack);
void			rev_rotate(t_stack *stack);
int				check_valid(t_stack *a, t_stack *b);
int				valid_ops(char *op);
void			stack_del(t_stack **stack);
void			display(int *list, int n);
void 			quicksort(t_stack *a, t_stack *b);
void			short_sort(t_stack *a, t_stack *b);
int				check_stack(t_stack *stack);
void			autre_tri(t_stack *a, t_stack *b, int pivot);
int				get_pivot(t_stack *a);
int				get_pivot_sort(t_stack *a, t_stack *b);
int				lowest_num(t_stack *a, t_stack *b);
int				is_in_stack(t_stack *stack, int num);
int				higher(t_stack *a, t_stack *b);
int				get_index(t_stack *stack, int num);

#endif
