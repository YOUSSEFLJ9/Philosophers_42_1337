# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 18:53:10 by ymomen            #+#    #+#              #
#    Updated: 2024/05/26 02:59:58 by ymomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=CC
CFLAGS=-Wall -Wextra -Werror -pthread
SRC=main.c philo.c outils.c ft_atoi.c init.c simulation.c #threads.c monitor.c actions.c
OBJ=$(SRC:.c=.o)
NAME=philo
HEADER=philo.h
RM=rm -f

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re