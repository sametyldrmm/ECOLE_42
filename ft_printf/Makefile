# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 05:09:53 by syildiri          #+#    #+#              #
#    Updated: 2022/02/23 15:29:58 by syildiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf
CC = gcc
INC = ft_printf.h
CFLAGS = -Wall -Wextra 
ARFLAGS = -rcs
RM = rm -rf

SRCS	= ft_printf.c ft_printf_x.c ft_printf_s.c ft_printf_u.c ft_printf_p.c ft_printf_d.c ft_printf_c.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_d1.c
SRCS_BONUS = ft_printf_bonus.c ft_printf_x_bonus.c ft_printf_s_bonus.c ft_printf_u_bonus.c ft_printf_p_bonus.c ft_printf_d_bonus.c ft_printf_c_bonus.c ft_printf_utils_bonus.c ft_printf_utils_2_bonus.c ft_printf_d1_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJS)
	ar $(ARFLAGS) $(NAME).a $(OBJS)

%.o: %.c $(INC)
	$(CC) -c $< -o $@ $(CFLAGS) -g

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME).a

bonus: $(OBJS_BONUS)
	ar $(ARFLAGS) $(NAME).a $(OBJS_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re
