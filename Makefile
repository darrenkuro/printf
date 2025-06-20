# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:54:43 by dlu               #+#    #+#              #
#    Updated: 2025/06/20 23:37:35 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a

SRCDIR	:=	src
_SRC	:=	ft_printf.c parse_format.c parse_nbr.c print.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))

OBJDIR	:=	obj
OBJ		:=	$(addprefix $(OBJDIR)/, $(_SRC:.c=.o))

INCDIR	:=	include

CC			:=	cc
AR			:=	ar rcs
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror -g -MMD -MP
CPPFLAGS	:=	-I $(INCDIR)

.DEFAULT_GOAL	:=	all

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(NAME)

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

$(OBJDIR):
	@mkdir -p $@

$(NAME): $(OBJ)
	$(AR) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<