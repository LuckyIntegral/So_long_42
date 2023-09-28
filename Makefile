# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:47:23 by vfrants           #+#    #+#              #
#    Updated: 2023/09/28 20:19:26 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LINKS	= -lmlx -lXext -lX11
NAME	= so_long
SRCDIR	= ./mandatory/src

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libftprintf.a

INC		= ./mandatory/inc

SRCS	= ${SRCDIR}/sl_error.c \
		${SRCDIR}/sl_map_validation.c \
		${SRCDIR}/sl_map_validation_2.c \
		${SRCDIR}/sl_map.c \
		${SRCDIR}/sl_utils_general.c \
		${SRCDIR}/sl_close.c \
		${SRCDIR}/sl_moves.c \
		${SRCDIR}/sl_images.c \
		${SRCDIR}/sl_display.c \
		${SRCDIR}/main.c

OBJS	= ${SRCS:.c=.o}

%.o		: %.c
		${CC} -g ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		${CC} ${LINKS} -o $@ ${OBJS} -L . ./libft/libftprintf.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

debug	: fclean ${LIBFT} ${OBJS}
		${CC} -g ${LINKS} -o $@ ${OBJS} -L . ./libft/libftprintf.a

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
