# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 17:59:10 by msalembe          #+#    #+#              #
#    Updated: 2024/08/04 01:08:43 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	create_stadio.c \
	utils.c map.c \
	aux.c moves.c \
	check.c \
	check_extra.c \
	utils_extra.c \
	control.c \
	control_extra.c \
	ft_printf/src/ft_printf.c \
	ft_printf/src/ft_putheX.c \
	ft_printf/src/ft_puthex.c \
	ft_printf/src/ft_putnbr_fd.c \
	ft_printf/src/ft_putnbr.c \
	ft_printf/src/ft_putptr.c \
	ft_printf/src/ft_puts.c \
	ft_printf/src/ft_putunbr.c \

INCLUDE = -I includes -I ft_printf/includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MIN_FLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

CC = cc

# ---------------------- EFFECTS ------------------------------- #

# COLORS
BLUE =  \033[1;34m
GREEN =  \033[1;32m
YELLOW =  \033[1;33m
RESET = \033[1;0m

# VARS

CREATING = echo "🤖 $(BLUE)Creating the game, wait...$(RESET)"

CREATED = echo "⭐ $(GREEN)The game was created, you can play now!$(RESET)"

CLEANING_OBJ = echo "🫧  $(YELLOW)Deleting the Objects files!$(RESET)"

CLEANED = echo "✨ $(YELLOW)The game was deleted!$(RESET)"

all: $(NAME)

$(NAME): start proccess

start:
	@$(CREATING)

proccess: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_PRINT) -Lminilibx-linux $(MIN_FLAGS) -o $(NAME)
	@$(CREATED)

clean:
	@rm -rf $(OBJ)
	@$(CLEANING_OBJ)

fclean: clean
	@rm -rf $(NAME)
	@$(CLEANED)

.c.o:
	@${CC} ${FLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

re: fclean all

.PHONY: all start proccess clean fclean