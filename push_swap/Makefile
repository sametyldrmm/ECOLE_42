# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:23:46 by aabduvak          #+#    #+#              #
#    Updated: 2022/03/24 05:45:59 by syildiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_rules1.c ft_rules2.c ft_rules3.c main.c ps1.c ps2.c ps3.c ps4.c 
OBJS			= $(SRCS:.c=.o)
NAME			= push_swap
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all : ${NAME}

$(NAME) : ${OBJS}
	make -C libft
	$(CC) $(OBJS) -o $(NAME) libft/libft.a

clean :
	make clean -C ./libft
	${RM} ${OBJS}

fclean : clean
	make fclean -C ./libft
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
