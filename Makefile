#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 17:19:56 by mtrotsen          #+#    #+#              #
#    Updated: 2019/02/07 17:19:59 by mtrotsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRCS = ft_printf.c distribute_c.c other_print.c distribute_s.c \
ft_atoi.c ft_putchar.c distribute_percent.c ft_strcmp.c distribute_p.c \
itoa_base.c distribute_di.c ft_putdif.c distribute_x.c distribute_u.c \
distribute_o.c distribute_f.c ft_strjoin.c
OBJ = ft_printf.o distribute_c.o other_print.o distribute_s.o \
ft_atoi.o ft_putchar.o distribute_percent.o ft_strcmp.o distribute_p.o \
itoa_base.o distribute_di.o ft_putdif.o distribute_x.o distribute_u.o \
distribute_o.o distribute_f.o ft_strjoin.o

all: $(NAME)

$(NAME):
	@echo Start
	@gcc -c $(SRCS)
	@echo Compiled files.o
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Created $(NAME) 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
