# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:16:17 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/22 15:53:39 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/parse.c src/pars2.c src/parse3.c src/parse4.c src/ft_basic.c src/ft_print_array.c src/ft_print.c src/ft_rush.c
OBJS	= ${SRCS:.c=.o}
INCL	= includes

NAME	= rush-02

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -I ${INCL} -c $< -o ${<:.c=.o} -g

all:		${NAME}

${NAME}:	${OBJS}
				${CC} -o ${NAME} ${OBJS}

clean:
				rm -rf ${OBJS}

fclean:		clean
				rm -rf ${NAME}

re:			fclean all

clear:
				clear

compile:		clear all

.PHONY: 	all clean fclean re clear compile
