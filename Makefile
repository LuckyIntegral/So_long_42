# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:47:23 by vfrants           #+#    #+#              #
#    Updated: 2023/09/30 19:56:03 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LINKS		= -lmlx -lXext -lX11
NAME		= so_long
BONUS_NAME	= so_long_bonus
SRCDIR		= ./mandatory/src
BONUS_SRC	= ./bonus/src

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libftprintf.a

INC			= ./mandatory/inc

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

BONUS_SRCS	= ${BONUS_SRC}/sl_map_validation_bonus.c \
			${BONUS_SRC}/sl_map_validation_2_bonus.c \
			${BONUS_SRC}/sl_map_bonus.c \
			${BONUS_SRC}/sl_utils_general_bonus.c \
			${BONUS_SRC}/sl_close_bonus.c \
			${BONUS_SRC}/sl_moves_bonus.c \
			${BONUS_SRC}/sl_images_bonus.c \
			${BONUS_SRC}/sl_display_bonus.c \
			${BONUS_SRC}/main_bonus.c

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

%.o		: %.c
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		${CC} ${LINKS} -o $@ ${OBJS} -L . ./libft/libftprintf.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

bonus	: ${LIBFT} ${BONUS_OBJS}
		${CC} ${LINKS} -o ${BONUS_NAME} ${BONUS_OBJS} -L . ./libft/libftprintf.a

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}
		rm -f ${BONUS_OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}
		rm -f ${BONUS_NAME}
		rm -f debug

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
# .SILENT
