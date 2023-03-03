# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 15:00:54 by bsilva-c          #+#    #+#              #
#    Updated: 2022/11/26 15:36:21 by bsilva-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -I.
DEPS=ft_printf.h

SRC=ft_printf_base.c ft_printf.c ft_printf_utils.c ft_utoa.c
OBJ=$(SRC:.c=.o)
NAME=libftprintf.a

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@ar rcs $(NAME) $(OBJ)
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
