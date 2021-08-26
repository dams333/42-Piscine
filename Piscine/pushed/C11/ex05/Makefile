# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 09:06:52 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/19 10:18:19 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c functions.c

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

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
