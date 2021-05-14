# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtresa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 12:17:04 by gtresa            #+#    #+#              #
#    Updated: 2020/12/19 13:09:37 by gtresa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c output_format.c output_type.c parsing.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

FLAGS		= -Wall -Wextra -Werror

HEADER		= libftprintf.h

.c.o:
		gcc ${FLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS} ${HEADER}
			${MAKE} bonus -C ./libft
			cp ./libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
		${MAKE} clean -C ./libft
		rm -rf ${OBJS}

fclean:	clean
		${MAKE} fclean -C ./libft
		rm -rf ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
