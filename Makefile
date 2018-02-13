# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 16:24:08 by clecalie          #+#    #+#              #
#    Updated: 2018/02/09 17:40:12 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

PATH_SRCS = srcs/

HEADERS_FILES = includes/

SRCS_CHECKER =	$(PATH_SRCS)checker.c \
	   			$(PATH_SRCS)handle.c \
	   			$(PATH_SRCS)check_error.c \
	   			$(PATH_SRCS)new_stack.c \
	   			$(PATH_SRCS)op.c

SRCS_PUSH_SWAP =	$(PATH_SRCS)push_swap.c \
	   				$(PATH_SRCS)check_error.c \
					$(PATH_SRCS)new_stack.c \
					$(PATH_SRCS)op.c \
					$(PATH_SRCS)get_pivot.c \
					$(PATH_SRCS)sort_util.c \
					$(PATH_SRCS)sort_a.c \
					$(PATH_SRCS)quicksort.c \
					$(PATH_SRCS)short_sort.c

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJS_CHECKER_FILTERED = $(notdir $(OBJS_CHECKER))

OBJS_PUSH_SWAP_FILTERED = $(notdir $(OBJS_PUSH_SWAP))

LIB_OBJS = libft/*.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJS_CHECKER_FILTERED)
	make -C libft/
	gcc $(FLAGS) $(OBJS_CHECKER_FILTERED) $(LIB_OBJS) -o $(NAME_1)

$(NAME_2): $(OBJS_PUSH_SWAP_FILTERED)
	gcc $(FLAGS) $(OBJS_PUSH_SWAP_FILTERED) $(LIB_OBJS) -o $(NAME_2)

%.o: $(PATH_SRCS)%.c
	gcc -c $< $(FLAGS) -I libft/includes -I $(HEADERS_FILES)

clean:
	make -C libft/ clean
	rm -f $(OBJS_CHECKER_FILTERED) $(OBJS_PUSH_SWAP_FILTERED)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all clean fclean re
