# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:47:23 by vfrants           #+#    #+#              #
#    Updated: 2023/10/01 00:58:20 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LINKS		= -lmlx -lXext -lX11

NAME		= so_long
NAME_B		= so_long_bonus

SRCDIR		= ./mandatory/src
SRCDIR_B	= ./bonus/src

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libftprintf.a

SRCS		= ${SRCDIR}/sl_error.c \
			${SRCDIR}/sl_map_validation.c \
			${SRCDIR}/sl_map_validation_2.c \
			${SRCDIR}/sl_map.c \
			${SRCDIR}/sl_utils_general.c \
			${SRCDIR}/sl_close.c \
			${SRCDIR}/sl_moves.c \
			${SRCDIR}/sl_images.c \
			${SRCDIR}/sl_display.c \
			${SRCDIR}/main.c

SRCS_B		= ${SRCDIR_B}/sl_map_validation_bonus.c \
			${SRCDIR_B}/sl_map_validation_2_bonus.c \
			${SRCDIR_B}/sl_map_bonus.c \
			${SRCDIR_B}/sl_utils_general_bonus.c \
			${SRCDIR_B}/sl_close_bonus.c \
			${SRCDIR_B}/sl_moves_bonus.c \
			${SRCDIR_B}/sl_images_bonus.c \
			${SRCDIR_B}/sl_display_bonus.c \
			${SRCDIR_B}/main_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

%.o		: %.c
		${CC} -g ${CFLAGS} ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		${CC} ${LINKS} -o $@ ${OBJS} -L . ./libft/libftprintf.a

all		: ${NAME}

${NAME_B}	: ${LIBFT} ${OBJS_B}
		${CC} ${LINKS} -o $@ ${OBJS_B} -L . ./libft/libftprintf.a

bonus	: ${NAME_B}

${LIBFT}:
		make -C $(LIBDIR) all

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME} ${NAME_B}

re		: fclean all

reb		: fclean bonus

.PHONY: all, bonus, clean, fclean, re
