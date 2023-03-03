# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:13:04 by bsilva-c          #+#    #+#              #
#    Updated: 2022/11/15 11:07:26 by bsilva-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPS=libft.h ft_printf/libftprintf.a

SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ=$(SRC:.c=.o)
NAME=libft.a

all: deps $(NAME)
deps:
	@$(MAKE) -C ./ft_printf
$(NAME): $(OBJ) $(DEPS)
	@cp ft_printf/libftprintf.a $(NAME)
	@ar rs $(NAME) $(OBJ)
clean:
	@$(MAKE) $@ -C ./ft_printf
	@rm -rf $(OBJ)
fclean: clean
	@$(MAKE) $@ -C ./ft_printf
	@rm -rf $(NAME)
re: fclean all
	@$(MAKE) $@ -C ./ft_printf
