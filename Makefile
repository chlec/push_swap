# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 16:24:08 by clecalie          #+#    #+#              #
#    Updated: 2018/01/16 11:46:03 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker

SRCS = checker.c \
	   handle.c \
	   check_valid_arg.c

OBJS = $(SRCS:.c=.o)

LIB_OBJS = libft/*.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJS)
	make -C libft/
	gcc $(FLAGS) $(OBJS) $(LIB_OBJS) -o $(NAME_CHECKER)

%.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re
