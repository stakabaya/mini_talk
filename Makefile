# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 02:04:56 by stakabay          #+#    #+#              #
#    Updated: 2021/12/01 18:55:32 by stakabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME := client
SERVER_NAME := server

CC := gcc
CFLAGS := #-Wall -Wextra -Werror

CLSRCNAME	= client.c
SRSRCNAME	= server.c
CLOBJS := $(CLSRCNAME:.c=.o)
SROBJS := $(SRSRCNAME:.c=.o)

LIBFT := libft.a
LIBFT_DIR := ./libft/
RM := rm -f

all:$(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):$(CLOBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CLOBJS) $(LIBFT_DIR)$(LIBFT) -o $@

$(SERVER_NAME):$(SROBJS)
	$(CC) $(CFLAGS) $(SROBJS) $(LIBFT_DIR)$(LIBFT) -o $@

clean:
	$(RM) $(CLOBJS)
	$(RM) $(SROBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(CLIENT_NAME) $(LIBFT)
	$(RM) $(SERVER_NAME) $(LIBFT)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		clean fclean re all
