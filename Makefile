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

NAME = ft_printf
SRCS = main.c ft_printf.c
LIB = ./libft/libft.a

$(NAME):
	@make -C ./libft
	@gcc -o $(NAME) $(SRCS) $(LIB)

all: $(NAME)

clean:
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
