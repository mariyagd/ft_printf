# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 12:21:59 by mdanchev          #+#    #+#              #
#    Updated: 2022/11/02 16:07:51 by mdanchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_char.c ft_printf_str.c ft_printf_int.c \
	   ft_count_int.c ft_put_unsnbr_fd.c ft_printf_unsint.c \
	   ft_count_unsigned_int.c ft_printf_address.c ft_printf_hexa.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME): libft/libft.a ${OBJS}
	cp $< $@
	ar rcs $@ ${OBJS}

clean:
		${RM} ${OBJS} 
		$(MAKE) -C libft clean

fclean:	clean
		${RM} ${NAME}
		$(MAKE) -C libft fclean

re:		fclean all

libft/libft.a:
	$(MAKE) -C libft


.PHONY:	all clean fclean re
