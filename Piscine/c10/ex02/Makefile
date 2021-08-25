# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 21:50:50 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/25 16:59:22 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/read_files.c src/atoi.c src/buffer.c
OBJS	= ${SRCS:.c=.o}
INCL	= includes

NAME	= ft_tail

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBDIR	= util
LIBNAME	= util

.c.o:
				${CC} ${CFLAGS} -I ${INCL} -c $< -o ${<:.c=.o}

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
