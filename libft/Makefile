# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:10:51 by vfrants           #+#    #+#              #
#    Updated: 2023/09/19 22:08:36 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libft.a

SRCS	= ft_pf_vac.c ft_pf_vaid.c ft_pf_vap.c ft_pf_vas.c ft_pf_vau.c \
		ft_pf_vax.c ft_pf_vaxx.c ft_pf_utils.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

%.o		: %.c
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}	: ${LIBFT} ${OBJS}
		cp ${LIBFT} ${NAME}
		ar -rcs $@ ${OBJS}

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

bonus	: all

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
