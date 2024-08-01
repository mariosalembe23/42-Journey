# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:26:15 by msalembe          #+#    #+#              #
#    Updated: 2024/06/28 01:23:26 by msalembe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Arquivos
SERVER		=	server.c

CLIENT		=	client.c

SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Variáveis ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

NAME		=	server

# ------------------------------ Cores ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Mensagens ------------------------------

COMP_START	=	printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR) Iniciando a Compilação...\n"

SERV_READY	=	printf "📥 $(BOLD_CYAN)Servidor Pronto!\n"

CLI_READY	=	printf "📟 $(BOLD_PURPLE)Cliente Pronto!\n"

CLEANED		=	printf "💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removendo todos \".o\" files \n"

FCLEANED	=	printf "🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removendo os Executáveis \n"

# ------------------------------ Regras ------------------------------

all: $(NAME)

$(NAME): comp_start server client

comp_start:
	@$(COMP_START)

server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@$(SERV_READY)

client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@$(CLI_READY)

clean:
	@rm -rf $(OBJS)
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@$(FCLEANED)

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all server client clean fclean re
