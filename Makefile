# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/09/23 05:36:13 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# =============================== VARIABLES ================================== #
NAME = minishell
CC = gcc
RM = rm -rf
MAKE = make --no-print-directory
FLAGS = -L/usr/local/lib -I/usr/local/include -lreadline -Wall -Wextra -Werror

# =========================== SOURCES ======================================== #
SRC_PATH = src/
SRC = test.c
LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a
INC =	-I ./inc/

# =========================== DIRECTORIES ==================================== #
DIR_OBJ = $(SRC_PATH)obj/
OBJ = $(addprefix $(DIR_OBJ), $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ), $(SRC:.c=.d))


# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
P = \033[35m
C = \033[36m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m


# ========================== MAKE RULES ===================================== #
all: dir $(NAME)

-include $(DEP)

dir:
	@mkdir -p $(DIR_OBJ)
	@$(MAKE) -C $(LIB_PATH)

print:
	@echo "$(DIR_OBJ)"
	@echo "$(OBJ)"

$(DIR_OBJ)%.o: $(SRC_PATH)%.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)
	@printf "\r$(G)$<$(E) to $(P)$@$(E)                           "

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB) $(FLAGS) -no-pie
	@echo "\n$(G)$(NAME) succesfully compiled...$(E)"


# ========================== CLEAN   ===================================== #

fclean: clean
	$(RM) $(NAME) $(NAME)
	@$(MAKE) clean -C $(LIB_PATH)

clean:
	$(RM) $(DIR_OBJ)

re: fclean all
.PHONY: clean fclean re
.SILENT: