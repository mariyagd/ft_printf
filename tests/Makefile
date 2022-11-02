# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 22:46:16 by pmarquis          #+#    #+#              #
#    Updated: 2022/11/02 16:54:51 by mdanchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: tests leaks clean mrproper re ../libftprintf.a

NAME = test

.DEFAULT_GOAL := $(NAME)

# path to <ft_printf.h>
INCDIR = ..
# show OK results
SHOW_OK = 1
# stop at first error
STOP = 0

CC = gcc
CFLAGS = -O2 -Wno-format -Wformat-extra-args

ifeq ($(shell uname -s),Linux)
LEAKS = valgrind --leak-check=full --quiet
else
LEAKS = leaks -atExit -quiet --
endif

../libftprintf.a:
	$(MAKE) -C ..

$(NAME): ft_printf_tester.c ../libftprintf.a
	$(CC) $(CFLAGS) -DSHOW_OK=$(SHOW_OK) -DSTOP=$(STOP) -I$(INCDIR) $^ -o $@

tests: $(NAME)
	./$<

leaks: $(NAME)
	$(LEAKS) ./$<

clean:
	rm -f _test1 _test2

fclean: clean
	rm -f $(NAME)

mrproper: fclean

re: fclean $(NAME)

