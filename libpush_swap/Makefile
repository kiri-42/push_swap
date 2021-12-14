# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:13:38 by tkirihar          #+#    #+#              #
#    Updated: 2021/12/14 17:15:41 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libpush_swap.a

SRCS =

OBJS =		$(SRCS:.c=.o)

CC =		gcc
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I ./includes/ -c $< -o $(<:%.c=%.o)

fclean:		clean
			$(RM) $(NAME)

clean:
			$(RM) $(OBJS)

re:			fclean all

.PHONY:		all clean fclean re