# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 18:53:10 by ymomen            #+#    #+#              #
#    Updated: 2024/06/03 19:42:20 by ymomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=CC
CFLAGS=-Wall -Wextra -Werror -pthread #-g -fsanitize=thread
SRC=main.c philo.c outils.c ft_atoi.c init.c simulation.c mutex_vrbls.c monitor.c
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