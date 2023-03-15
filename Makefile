# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 16:06:14 by bsilva-c          #+#    #+#              #
#    Updated: 2023/03/15 19:20:17 by bsilva-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPS=minitalk.h libft/libft.a

CLIENT=client
SRC_CLIENT=client.c
OBJ_CLIENT=$(SRC_CLIENT:.c=.o)
SERVER=server
SRC_SERVER=server.c
OBJ_SERVER=$(SRC_SERVER:.c=.o)

CLIENT_BONUS=client_bonus
SRC_CLIENT_BONUS=client_bonus.c
OBJ_CLIENT_BONUS=$(SRC_CLIENT_BONUS:.c=.o)
SERVER_BONUS=server_bonus
SRC_SERVER_BONUS=server_bonus.c
OBJ_SERVER_BONUS=$(SRC_SERVER_BONUS:.c=.o)

LIBFT=libft/libft.a

all: deps $(CLIENT) $(SERVER)
deps:
	@$(MAKE) -C ./libft
$(CLIENT): $(OBJ_CLIENT) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
$(SERVER): $(OBJ_SERVER) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)
$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)
clean:
	@$(MAKE) $@ -C ./libft
	@rm -rf $(OBJ_CLIENT)
	@rm -rf $(OBJ_SERVER)
	@rm -rf $(OBJ_CLIENT_BONUS)
	@rm -rf $(OBJ_SERVER_BONUS)
fclean: clean
	@$(MAKE) $@ -C ./libft
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT_BONUS)
	@rm -rf $(SERVER_BONUS)
re: fclean all
	@$(MAKE) $@ -C ./libft
bonus: deps $(CLIENT_BONUS) $(SERVER_BONUS)
