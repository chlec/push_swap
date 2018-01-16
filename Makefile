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

PATH_CHECKER = checker_src/

SRCS_CHECKER =	$(PATH_CHECKER)checker.c \
	   			$(PATH_CHECKER)handle.c \
	   			$(PATH_CHECKER)check_valid_arg.c \
	   			$(PATH_CHECKER)new_pile.c \
	   			$(PATH_CHECKER)op.c

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_CHECKER_FILTERED = $(notdir $(OBJS_CHECKER))

LIB_OBJS = libft/*.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJS_CHECKER)
	make -C libft/
	gcc $(FLAGS) $(OBJS_CHECKER_FILTERED) $(LIB_OBJS) -o $(NAME_CHECKER)

%.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJS_CHECKER_FILTERED)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re
