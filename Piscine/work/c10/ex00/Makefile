# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 21:50:50 by dhubleur          #+#    #+#              #
#    Updated: 2021/08/23 18:19:07 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

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
