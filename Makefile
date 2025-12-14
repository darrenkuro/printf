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

# ------------------------ Project Metadata
NAME	:=	printf
TARGET	:=	libftprintf.a

# ------------------------ Directories
SRCDIR	:=	src
OBJDIR	:=	obj
INCDIR	:=	include

# ------------------------ Files
_SRC	:=	ft_printf.c parse_format.c parse_nbr.c print.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))
OBJ		:=	$(addprefix $(OBJDIR)/, $(_SRC:.c=.o))

# ------------------------ Toolchain & Flags
CC		:=	cc
AR		:=	ar rcs
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror -MMD -MP
CPPFLAGS:=	-I $(INCDIR)

# ------------------------ Build Settings
.DEFAULT_GOAL	:= all

PAD	?=	0 # Inherited label length for alignment
DEBUG	?=	0
ifeq ($(DEBUG),1)
	CFLAGS	+=	-g
endif

# === Rules & Targets
.PHONY: all
all: $(TARGET)

.PHONY: bonus
bonus: $(TARGET)

.PHONY: clean
clean:
	@if [ -d "$(OBJDIR)" ]; then \
		printf "%-*s 🧹 Removing $(OBJDIR)/..." $(PAD) "[$(NAME)]"; \
		$(RM) -r $(OBJDIR); \
		echo " ✅ "; \
	fi

.PHONY: fclean
fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		printf "%-*s 🗑️ Removing $(TARGET)..." $(PAD) "[$(NAME)]"; \
		$(RM) $(TARGET); \
		echo " ✅ "; \
	fi

.PHONY: re
re: fclean all

$(OBJDIR):
	@printf "%-*s 📁 Creating: $@ directory..." $(PAD) "[$(NAME)]"
	@mkdir -p $@
	@echo " ✅ "

$(TARGET): $(OBJ)
	@printf "%-*s 📦 Building: $@" $(PAD) "[$(NAME)]"
	@$(AR) $@ $^
	@echo " ✅ "

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf "%-*s ⚙️ Compiling: $<..." $(PAD) "[$(NAME)]"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@echo " ✅ "

.DELETE_ON_ERROR:     # Delete target build that's incomplete
-include $(OBJ:.o=.d) # Dependency injection
