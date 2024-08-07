# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:26:15 by msalembe          #+#    #+#              #
#    Updated: 2024/08/07 09:58:43 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Arquivos
SERVER_SRC  = server.c
CLIENT_SRC  = client.c

# BONUS
BONUS_SERVER_SRC = bonus/server_bonus.c
BONUS_CLIENT_SRC = bonus/client_bonus.c

SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

BONUS_SERVER_OBJS = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRC:.c=.o)

OBJS        = $(CLIENT_OBJS) \
              $(SERVER_OBJS)

OBJS_BONUS  = $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)

# ------------------------------ Variáveis ------------------------------

CC          = cc
FLAGS       = -Wall -Wextra -Werror
INCLUDE     = -I include

SERVER_NAME = server
CLIENT_NAME = client

SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus

# ------------------------------ Cores ------------------------------

BOLD_PURPLE = \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_YELLOW = \033[1;33m
NO_COLOR    = \033[0m

# ------------------------------ Mensagens ------------------------------

COMP_START  = printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR) Iniciando a Compilação...\n$(NO_COLOR)"
SERV_READY  = printf "📥 $(BOLD_CYAN)Servidor Pronto!\n$(NO_COLOR)"
CLI_READY   = printf "📟 $(BOLD_PURPLE)Cliente Pronto!\n$(NO_COLOR)"

# ----------------------------- BONUS ------------------------------------
COMP_START_BONUS = printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR) Iniciando a Compilação...(BONUS)\n$(NO_COLOR)"
SERV_READY_BONUS = printf "📥 $(BOLD_CYAN)Servidor (BONUS) Pronto!\n$(NO_COLOR)"
CLI_READY_BONUS  = printf "📟 $(BOLD_PURPLE)Cliente (BONUS) Pronto!\n$(NO_COLOR)"

CLEANED     = printf "💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removendo todos \".o\" files \n$(NO_COLOR)"
FCLEANED    = printf "🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removendo os Executáveis \n$(NO_COLOR)"

# ------------------------------ Regras ------------------------------

all: comp_start $(SERVER_NAME) $(CLIENT_NAME)

comp_start:
	@$(COMP_START)

$(SERVER_NAME): $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@$(SERV_READY)

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@$(CLI_READY)

bonus: comp_start_bonus $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

comp_start_bonus:
	@$(COMP_START_BONUS)

$(SERVER_NAME_BONUS): $(BONUS_SERVER_OBJS)
	@$(CC) $(FLAGS) $(BONUS_SERVER_OBJS) -o $(SERVER_NAME_BONUS)
	@$(SERV_READY_BONUS)

$(CLIENT_NAME_BONUS): $(BONUS_CLIENT_OBJS)
	@$(CC) $(FLAGS) $(BONUS_CLIENT_OBJS) -o $(CLIENT_NAME_BONUS)
	@$(CLI_READY_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	@$(FCLEANED)

.c.o:
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

re: fclean all

.PHONY: all comp_start server client bonus comp_start_bonus server_name_bonus client_server_bonus clean fclean re
