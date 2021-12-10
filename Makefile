# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 18:29:18 by efinicke          #+#    #+#              #
#    Updated: 2021/09/13 18:29:20 by efinicke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	00_create_stack.c \
01_argv_parsing1.c \
01_argv_parsing2.c \
02_libft_fcts.c \
03_lst_functions.c \
04_commands1.c \
04_commands2.c \
04_commands3.c \
05_stack_parsing1.c \
05_stack_parsing2.c \
05_stack_parsing3.c \
06_go_algo1.c \
06_go_algo2.c \
main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY:	all clean fclean re