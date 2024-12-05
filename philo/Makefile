# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 21:45:43 by miwasa            #+#    #+#              #
#    Updated: 2024/12/05 12:47:12 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

INCS_DIR	:= ./incs
SRCS_DIR	:= ./srcs
OBJS_DIR	:= ./objs
MAIN		:= ./main.c
LIBS		:= -pthread

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(INCS_DIR) -g

SRCS		:= \
	philo.c \
	cleanup.c \
	init.c \
	monitor_philo.c \
	parse_arguments.c \
	philo_action.c \
	philo_routine.c \
	start_simulation.c \
	print_action.c \
	utils.c

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
