# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 21:50:50 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/22 17:39:39 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/print.c src/read.c src/print2.c src/read2.c
INCL	= includes
OBJS	= ${SRCS:.c=.o}

NAME	= ft_hexdump

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBDIR	= util/.
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
