# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 21:45:43 by miwasa            #+#    #+#              #
#    Updated: 2024/12/05 10:25:49 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

INCS_DIR	:= ./incs
SRCS_DIR	:= ./srcs
OBJS_DIR	:= ./objs
MAIN		:= ./main.c
LIBS		:= -pthread

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(INCS_DIR)

SRCS		:= \
	philo.c

OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o)) \
				$(OBJS_DIR)/main.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/main.o: $(MAIN)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
