# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:58:34 by tkirihar          #+#    #+#              #
#    Updated: 2021/12/14 20:27:31 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		./push_swap/srcs/push_swap

NAME_B = 	./checker/srcs/checker

SRCS = 		./push_swap/srcs/main.c \
			./push_swap/srcs/A_to_B.c \
			./push_swap/srcs/A_to_B_command_case.c \
			./push_swap/srcs/B_to_A.c \
			./push_swap/srcs/B_to_A_command_case1~5.c \
			./push_swap/srcs/B_to_A_command_case6.c \
			./push_swap/srcs/check_arg.c \
			./push_swap/srcs/check_sort.c \
			./push_swap/srcs/check_three_sort.c \
			./push_swap/srcs/command_push.c \
			./push_swap/srcs/command_rotate.c \
			./push_swap/srcs/command_swap.c \
			./push_swap/srcs/finish_error.c \
			./push_swap/srcs/init_count.c \
			./push_swap/srcs/init_stack.c \
			./push_swap/srcs/reset_stack.c \
			./push_swap/srcs/search_min.c \
			./push_swap/srcs/search_pivot.c \
			./push_swap/srcs/short_sort.c \
			./push_swap/srcs/sort.c \
			./push_swap/srcs/three_sort.c


SRCS_B = 	./checker/srcs/main.c \
			./checker/srcs/check_arg.c \
			./checker/srcs/check_empty.c \
			./checker/srcs/check_sort.c \
			./checker/srcs/command_push.c \
			./checker/srcs/command_rotate.c \
			./checker/srcs/command_swap.c \
			./checker/srcs/init_stack.c \
			./checker/srcs/sort.c

OBJS = 		$(SRCS:.c=.o)

OBJS_B = 	$(SRCS_B:.c=.o)

LIBFT = 	./libft-1.4.1/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $^ -o $@

$(NAME_B):	$(OBJS_B) $(LIBFT)
			$(CC) $^ -o $@

$(LIBFT):
			make -C libft bonus

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME_B) $(NAME_B)

re:			fclean all

bonus:		$(NAME) $(NAME_B)

.PHONY:		all clean fclean re bonus