# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 16:24:08 by clecalie          #+#    #+#              #
#    Updated: 2018/02/14 14:43:56 by clecalie         ###   ########.fr        #
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
					$(PATH_SRCS)sort_a.util.c \
					$(PATH_SRCS)sort_a.c \
					$(PATH_SRCS)sort_b.c \
					$(PATH_SRCS)quicksort.c \
					$(PATH_SRCS)short_sort.c

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJS_CHECKER_FILTERED = $(notdir $(OBJS_CHECKER))

OBJS_PUSH_SWAP_FILTERED = $(notdir $(OBJS_PUSH_SWAP))

LIB_OBJS = libft/ft_putendl.o \
		   libft/ft_atoi.o \
		   libft/ft_isdigit.o \
		   libft/ft_putchar.o \
		   libft/ft_putendl_fd.o \
		   libft/ft_putnbr.o \
		   libft/ft_strdel.o \
		   libft/ft_strequ.o \
		   libft/ft_strlen.o \
		   libft/get_next_line.o \
		   libft/ft_memcpy.o \
		   libft/ft_putchar_fd.o \
		   libft/ft_putstr.o \
		   libft/ft_putstr_fd.o \
		   libft/ft_strchr.o \
		   libft/ft_strcpy.o \
		   libft/ft_strdup.o \
		   libft/ft_strnew.o \
		   libft/ft_strsub.o \
		   libft/ft_bzero.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJS_CHECKER_FILTERED)
	@/bin/echo -n "Compiling libft..."
	@make -C libft/
	@echo " [\033[0;32mOK\033[0m]"
	@/bin/echo -n "Compiling checker..."
	@gcc $(FLAGS) $(OBJS_CHECKER_FILTERED) $(LIB_OBJS) -o $(NAME_1)
	@echo " [\033[0;32mOK\033[0m]"

$(NAME_2): $(OBJS_PUSH_SWAP_FILTERED)
	@/bin/echo -n "Compiling push_swap..."
	@gcc $(FLAGS) $(OBJS_PUSH_SWAP_FILTERED) $(LIB_OBJS) -o $(NAME_2)
	@echo " [\033[0;32mOK\033[0m]"

%.o: $(PATH_SRCS)%.c
	@gcc -c $< $(FLAGS) -I libft/includes -I $(HEADERS_FILES)

clean:
	@make -C libft/ clean
	@/bin/echo "Libft cleaned!"
	@rm -f $(OBJS_CHECKER_FILTERED) $(OBJS_PUSH_SWAP_FILTERED)
	@/bin/echo "Objects files cleaned!"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME_1) $(NAME_2)
	@/bin/echo "Binaries files cleaned!"

re: fclean all

.PHONY: all clean fclean re
