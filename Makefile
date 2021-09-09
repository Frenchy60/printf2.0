# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:34:48 by agraton           #+#    #+#              #
#    Updated: 2021/09/09 17:12:46 by agraton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c handlenum.c strmod.c playingwithnum.c struct.c handlechar.c \
	   randomhelp.c handlehex.c


OBJS = $(addprefix srcs/, ${SRCS:.c=.o})

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

all:	${NAME}

bonus: all

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
