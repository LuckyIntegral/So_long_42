# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:47:23 by vfrants           #+#    #+#              #
#    Updated: 2023/09/24 22:38:16 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LINKS	= -lmlx -lXext -lX11
NAME	= so_long

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libftprintf.a

INC		= ./inc

SRCS	= sl_error.c sl_map_validation.c sl_map_validation_2.c sl_map.c \
		sl_utils_general.c sl_close.c sl_moves.c \
		main.c

OBJS	= ${SRCS:.c=.o}

%.o		: %.c
		${CC} -g ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		${CC} -lmlx -lXext -lX11 -lm -o $@ ${OBJS} -L . ./libft/libftprintf.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

debug	: fclean ${LIBFT} ${OBJS}
		${CC} -g -lmlx -lXext -lX11 -lm -o $@ ${OBJS} -L . ./libft/libftprintf.a

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}
		rm -f debug

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
# .SILENT
