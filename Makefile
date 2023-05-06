# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:54:43 by dlu               #+#    #+#              #
#    Updated: 2023/05/06 21:54:59 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRC=ft_printf.c parse_format.c parse_nbr.c print.c utils.c
HDIR=includes
LIB=libft/libft.a
LIBDIR=libft
CC=cc
RM=/bin/rm -f
CFLAGS=-Wall -Wextra -Werror
_OBJ=$(SRC:.c=.o)
OBJ=$(addprefix srcs/,$(_OBJ))
AR=ar rcs

$(NAME): $(OBJ)
	@make -C $(LIBDIR) all >/dev/null
	@cp $(LIB) $(NAME)
	$(AR) $@ $^

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HDIR) -I $(LIBDIR)

all: $(NAME)

bonus: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
