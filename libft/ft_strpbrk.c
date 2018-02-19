/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:35:43 by clecalie          #+#    #+#             */
/*   Updated: 2018/02/19 14:41:17 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
				return ((char*)&s[i]);
			j++;
		}
		i++;
	}
	return (0);
}
