# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:29:49 by shinckel          #+#    #+#              #
#    Updated: 2023/06/10 12:02:42 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheader -g
#CFLAGS += -fsanitize=address

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# Define colors
RED := \033[1;41m
YELLOW := \033[1;103m
RESET := \033[0m

all: $(NAME)

# target -> library file -> invoke the make utility recursively
# -C allows to build targets in different directory than where Makefile resides
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW) Pipex compiled $(RESET)"

clean:
	find . -type f -name "*.txt" ! -name "grocery_list.txt" -exec rm -f {} +
	rm -f $(OBJ)
	@echo "$(RED) Clean .txt files $(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(RED) Clean all $(RESET)"

re: fclean all

clean_libft:
	$(MAKE) -C $(LIBFT_DIR) fclean

# actions that should be executed when the target is invoked
.PHONY: all clean fclean re clean_libft
