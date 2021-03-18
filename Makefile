# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 18:06:21 by mkomadin          #+#    #+#              #
#    Updated: 2021/02/22 13:36:49 by mkomadin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_getpadding.c ft_displate.c ft_checkstar.c ft_strdup.c ft_atoi.c ft_itoa.c ft_strlen.c ft_strlcpy.c ft_isdigit.c ft_precision.c ft_paddingleft.c ft_paddingright.c ft_point.c ft_vatochar.c ft_conv0.c ft_uitoa.c ft_putstr.c ft_convertbase.c ft_convertbase2.c ft_printf.c main.c

OBJS		=		${SRCS:.c=.o}

FLAGS		=		-c -Werror -Wall -Wextra

NAME		=		libftprintf.a

.c.o		:
	gcc ${FLAGS} -o $@ $<

all			:		${NAME}

$(NAME)		:		${OBJS}
	ar rcs ${NAME} ${OBJS}

clean		:
	rm -rf ${OBJS}

fclean		:	clean
	rm -rf ${NAME}

re			:		fclean	all

test		:		${OBJS}
	gcc -o test.a ${OBJS}
