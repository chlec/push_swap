/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:00:59 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/08 14:34:01 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_pile
{
	int		*num;
	int		len;
	int		sorted;
}				t_pile;

int				handle_ops(char *op, t_pile *a, t_pile *b);
int				only_number(char *str);
int				has_double(char *str, int *num, int len);
t_pile			*new_pile(int len);
void			swap(t_pile *pile);
void			push(t_pile *a, t_pile *b);
void			rotate(t_pile *pile);
void			rev_rotate(t_pile *pile);
int				check_valid(t_pile *a, t_pile *b);
int				valid_ops(char *op);
void			pile_del(t_pile **pile);
void			display(int *list, int n);
void 			quicksort(t_pile *a, t_pile *b);
void			short_sort(t_pile *a, t_pile *b);
int				check_stack(t_pile *pile);

#endif
