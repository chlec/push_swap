#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef enum Operation Operation;
enum Operation
{
    SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
};

char	*add_end(char *str, char *add)
{
	char	*ret;

	if (!str || !add)
		return (0);
	if (!(ret = ft_strnew(ft_strlen(str) + ft_strlen(add) + 1)))
		return (0);
	ft_strcat(ret, str);
	ft_strcat(ret, add);
	return (ret);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	char	*all_op;

	all_op = "";
	while ((ret = get_next_line(0, &line)) > 0)
	{
		all_op = add_end(all_op, line);
		all_op = add_end(all_op, "\n");
	}
	printf("Toutes les operations: %s\n", all_op);
	return (0);
}