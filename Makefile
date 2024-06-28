# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:13:45 by mjochum           #+#    #+#              #
#    Updated: 2024/06/28 10:42:55 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_printf.a

SOURCES =	ft_align.c  ft_chars.c  ft_initFlags.c  ft_printChar.c  \
			ft_printf.c  ft_printHex.c  ft_printNums.c  ft_utils.c

OBJECTS =	$(SOURCES:.c=.o)

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all