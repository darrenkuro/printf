# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:54:43 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 09:19:58 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	printf
PROJECT	:=	$$YELLOW[$(NAME)]$$RESET
TARGET	:=	libftprintf.a

INCDIR	:=	include

SRCDIR	:=	src
_SRC	:=	ft_printf.c parse_format.c parse_nbr.c print.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))

OBJDIR	:=	obj
OBJ		:=	$(addprefix $(OBJDIR)/, $(_SRC:.c=.o))

CC			:=	cc
AR			:=	ar rcs
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror -g -MMD -MP
CPPFLAGS	:=	-I $(INCDIR)

PAD_WIDTH		?=	19
.DEFAULT_GOAL	:=	all
.SILENT:

.PHONY: all
all: $(TARGET)

.PHONY: bonus
bonus: $(TARGET)

.PHONY: clean
clean:
	if [ -d "$(OBJDIR)" ]; then \
		printf "%-*s 🧹 Removing object files and obj directory..." \
		$(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) -r "$(OBJDIR)"; \
		echo " ✅ "; \
	fi

.PHONY: fclean
fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		printf "%-*s 🗑️ Removing $(TARGET)..." $(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) $(TARGET); \
		echo " ✅ "; \
	fi

.PHONY: re
re: fclean all

$(OBJDIR):
	printf "%-*s 📁 Creating: $@ directory..." $(PAD_WIDTH) "$(PROJECT)"
	mkdir -p $@
	echo " ✅ "

$(TARGET): $(OBJ)
	printf "%-*s 📦 Building: $@" $(PAD_WIDTH) "$(PROJECT)"
	$(AR) $@ $^
	echo " ✅ "

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	printf "%-*s ⚙️ Compiling: $<..." $(PAD_WIDTH) "$(PROJECT)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	echo " ✅ "