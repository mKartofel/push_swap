# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 19:36:03 by vfiszbin          #+#    #+#              #
#    Updated: 2022/05/27 16:52:32 by vfiszbin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = libftprintf.a

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

all: ${FT_PRINTF} push_swap

${FT_PRINTF}:
	${MAKE} -C ./ft_printf
	
push_swap : push_swap.o operations_a.o operations_b.o operations_a_and_b.o utils.o quicksort.o arg_checks.o stack_sorts.o
	${CC} ${FLAGS} push_swap.o operations_a.o operations_b.o operations_a_and_b.o utils.o quicksort.o  arg_checks.o stack_sorts.o ft_printf/libftprintf.a ft_printf/libft/libft.a -o push_swap

push_swap.o : push_swap.c push_swap.h
	${CC} ${FLAGS} -c push_swap.c -o push_swap.o

operations_a.o : operations_a.c push_swap.h
	${CC} ${FLAGS} -c operations_a.c -o operations_a.o
	
operations_b.o : operations_b.c push_swap.h
	${CC} ${FLAGS} -c operations_b.c -o operations_b.o

operations_a_and_b.o : operations_a_and_b.c push_swap.h
	${CC} ${FLAGS} -c operations_a_and_b.c -o operations_a_and_b.o

utils.o : utils.c push_swap.h
	${CC} ${FLAGS} -c utils.c -o utils.o

quicksort.o : quicksort.c push_swap.h
	${CC} ${FLAGS} -c quicksort.c -o quicksort.o

arg_checks.o : arg_checks.c push_swap.h
	${CC} ${FLAGS} -c arg_checks.c -o arg_checks.o

stack_sorts.o : stack_sorts.c push_swap.h
	${CC} ${FLAGS} -c stack_sorts.c -o stack_sorts.o

clean:
	${MAKE} clean -C ./ft_printf
	${RM} *.o

fclean: clean
	${MAKE} fclean -C ./ft_printf
	${RM} *.o
	${RM} push_swap

re: fclean all

.PHONY: all clean fclean re