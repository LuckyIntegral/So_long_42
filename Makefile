# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:47:23 by vfrants           #+#    #+#              #
#    Updated: 2023/09/20 15:44:26 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= so_long

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libftprintf.a

INC		= ./inc

SRCS	= ---

OBJS	= ${SRCS:.c=.o}

%.o		: %.c
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		${CC} -o $@ ${OBJS} -L . ./libft/libftprintf.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
# .SILENT
