# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 21:50:50 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/17 11:55:01 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/read_file.c src/read_standard_input.c
OBJS	= ${SRCS:.c=.o}
INCL	= includes

NAME	= ft_cat

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBDIR	= util
LIBNAME	= util

.c.o:
				${CC} ${CFLAGS} -I ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				${CC} -L${LIBDIR} -l${LIBNAME} -o ${NAME} ${OBJS}

clean:
				rm -rf ${OBJS}

fclean:		clean
				rm -rf ${NAME}

re:			fclean all

clear:
				clear

compile:		clear all	

.PHONY: 	all clean fclean re clear compile
