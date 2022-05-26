# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 19:36:03 by vfiszbin          #+#    #+#              #
#    Updated: 2022/05/26 16:27:56 by vfiszbin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = libftprintf.a

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

all: ${FT_PRINTF} push_swap

${FT_PRINTF}:
	${MAKE} -C ./ft_printf
	
push_swap : push_swap.o operations.o utils.o
	${CC} ${FLAGS} push_swap.o operations.o utils.o ft_printf/libftprintf.a ft_printf/libft/libft.a -o push_swap

push_swap.o : push_swap.c push_swap.h
	${CC} ${FLAGS} -c push_swap.c -o push_swap.o

operations.o : operations.c push_swap.h
	${CC} ${FLAGS} -c operations.c -o operations.o

utils.o : utils.c push_swap.h
	${CC} ${FLAGS} -c utils.c -o utils.o

clean:
	${MAKE} clean -C ./ft_printf
	${RM} *.o

fclean: clean
	${MAKE} fclean -C ./ft_printf
	${RM} *.o
	${RM} push_swap

re: fclean all

.PHONY: all clean fclean re