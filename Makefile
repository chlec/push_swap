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

NAME_1 = checker

NAME_2 = push_swap

PATH_SRCS = srcs/

HEADERS_FILES = includes/

SRCS_CHECKER =	$(PATH_SRCS)checker.c \
	   			$(PATH_SRCS)handle.c \
	   			$(PATH_SRCS)check_error.c \
	   			$(PATH_SRCS)new_pile.c \
	   			$(PATH_SRCS)op.c

SRCS_PUSH_SWAP =	$(PATH_PUSH_SWAP)main.c \
	   				$(PATH_CHECKER)new_pile.c \
	   				$(PATH_CHECKER)op.c

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_CHECKER_FILTERED = $(notdir $(OBJS_CHECKER))

LIB_OBJS = libft/*.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME_1)

$(NAME_1): $(OBJS_CHECKER)
	make -C libft/
	gcc $(FLAGS) $(OBJS_CHECKER_FILTERED) $(LIB_OBJS) -o $(NAME_1)

%.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes -I $(HEADERS_FILES)

clean:
	make -C libft/ clean
	rm -f $(OBJS_CHECKER_FILTERED)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME_1)

re: fclean all

.PHONY: all clean fclean re
