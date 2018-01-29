/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:16 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/26 14:25:45 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void exchange(int *x,int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return ((i+j) /2);
}
 
void quicksort(int *list, int m, int n)
{
    int key;
    int i;
    int j;
    int	k;

    printf("Quicksort function called with params %d and %d\n", m, n);
    if( m < n)
    {
        k = choose_pivot(m,n);
        if (m != k)
        {
	        printf("On echange index m: %d (contenu %d) avec index k: %d (contenu %d)\n", m, list[m], k, list[k]);
	        exchange(&list[m],&list[k]);
    	}
        key = list[m];
        i = m + 1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j && i != j)
            {
            	printf("On echange index i: %d (contenu %d) avec index j: %d (contenu %d)\n", i, list[i], j, list[j]);
                exchange(&list[i],&list[j]);
            }
        }
        /* swap two elements */
        if (m != j)
        {
	        printf("On echange index m: %d (contenu %d) avec index j: %d (contenu %d)\n", m, list[m], j, list[j]);
	        exchange(&list[m],&list[j]);
    	}
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
void display(int *list, const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
    printf("\n");
}

void	resolve(t_pile *a, t_pile *b)
{
	(void)b;
	printf("Avant:\n");
	display(a->num, a->len);
	quicksort(a->num, 0, a->len - 1);
	printf("Apres:\n");
	display(a->num, a->len);
}

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*b;
	char	**ops;

	if (argc > 2)
	{
		a = new_pile(argc - 1);
		b = new_pile(0);
		ops = 0;
		i = 1;
		while (i < argc)
		{
			if (!only_number(argv[i]) || has_double(argv[i], a->num, i - 1))
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			a->num[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		resolve(a, b);
	}
	return (0);
}
