# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:58:34 by tkirihar          #+#    #+#              #
#    Updated: 2021/12/19 20:30:25 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

NAME_B = 	checker

SRCS = 		./push_swap_dir/srcs/main.c \
			./push_swap_dir/srcs/A_to_B.c \
			./push_swap_dir/srcs/A_to_B_command_case.c \
			./push_swap_dir/srcs/B_to_A.c \
			./push_swap_dir/srcs/B_to_A_command_case1~5.c \
			./push_swap_dir/srcs/B_to_A_command_case6.c \
			./push_swap_dir/srcs/check_arg.c \
			./push_swap_dir/srcs/check_sort.c \
			./push_swap_dir/srcs/check_three_sort.c \
			./push_swap_dir/srcs/command_push.c \
			./push_swap_dir/srcs/command_rotate.c \
			./push_swap_dir/srcs/command_swap.c \
			./push_swap_dir/srcs/finish_error.c \
			./push_swap_dir/srcs/init_count.c \
			./push_swap_dir/srcs/init_stack.c \
			./push_swap_dir/srcs/reset_stack.c \
			./push_swap_dir/srcs/search_min.c \
			./push_swap_dir/srcs/search_pivot.c \
			./push_swap_dir/srcs/short_sort.c \
			./push_swap_dir/srcs/sort.c \
			./push_swap_dir/srcs/three_sort.c


SRCS_B = 	./checker_dir/srcs/main.c \
			./checker_dir/srcs/check_arg.c \
			./checker_dir/srcs/check_empty.c \
			./checker_dir/srcs/check_sort.c \
			./checker_dir/srcs/command_push.c \
			./checker_dir/srcs/command_rotate.c \
			./checker_dir/srcs/command_swap.c \
			./checker_dir/srcs/init_stack.c \
			./checker_dir/srcs/sort.c

OBJS = 		$(SRCS:.c=.o)

OBJS_B = 	$(SRCS_B:.c=.o)

LIBFT = 	libft-1.4.1

LIBFT_A = 	./libft-1.4.1/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

$(NAME):	$(OBJS) $(LIBFT_A)
			$(CC) $^ -o $@

$(NAME_B):	$(OBJS_B) $(LIBFT_A)
			$(CC) $^ -o $@

$(LIBFT_A):
			make -C $(LIBFT) bonus

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS_B)
			make -C $(LIBFT) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)
			make -C $(LIBFT) fclean

re:			fclean all

bonus:		$(NAME) $(NAME_B)

.PHONY:		all clean fclean re bonus