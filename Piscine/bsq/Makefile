CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes

SRCS		=	parsing/dynamic_buffer.c parsing/elements.c parsing/files.c parsing/ft.c parsing/ft_mini_atoi.c parsing/map_parser.c parsing/parser.c \
				solve/main.c solve/map_util.c solve/print.c solve/solve.c

NAME		=	bsq

OBJS		=	${SRCS:.c=.o}

OBJS_PATH	=	$(addprefix build/,${OBJS})

all		:	$(NAME)

build	:
	mkdir -p build/parsing build/solve

build/%.o	: srcs/%.c
	gcc ${CFLAGS} -c $< -I${INCLUDE} -o $@

$(NAME)	:	build ${OBJS_PATH}
	gcc ${OBJS_PATH} -o $(NAME)

clean	:
	rm -Rf build

fclean	:	clean
	rm -f ${NAME}

re		:	fclean	${NAME}

.PHONY	:	all clean fclean re
