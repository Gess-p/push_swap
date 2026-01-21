# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 11:10:24 by gpeixoto          #+#    #+#              #
#    Updated: 2026/01/15 11:19:16 by gpeixoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
NAME = push_swap
FLAGS = -Wall -Werror -Wextra -o $(NAME)
SRC = algo.c algo_utils.c errors.c ft_split.c main.c push_command.c reverse_rotate_cmd.c rotate_command.c set_a_nodes.c set_b_nodes.c set_stack.c stack_utils.c swap_command.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(FLAGS) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
