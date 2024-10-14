# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/10/14 11:55:01 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR				=	ar -rcs
CC				=	cc
RM				=	rm -rf

BIN_DIR			=	bin/
INC_DIR			=	inc/

# ============================ libft ========================================= #

LIBFT_DIR		=	$(ROOT_DIR)lib/libft/
LIBFT			=	$(LIBFT_DIR)libft.a

# ============================ modules ======================================= #

#	prompt
PROMPT_ARCHIVE	=	$(BIN_DIR)prompt.a
MODULE_ARCHIVE	:=	$(PROMPT_ARCHIVE)

#	core
CORE_ARCHIVE	=	$(BIN_DIR)core.a
MODULE_ARCHIVE	+=	$(CORE_ARCHIVE)

# ============================ cflags ======================================== #

CFLAGS			:=	-Wall -Wextra -Werror

#	dependencies
CFLAGS			+=	-MMD

#	includes
CINC			+=	-I$(LIBFT_DIR) 
CINC			+=	-I$(INC_DIR) 
CFLAGS			+=	$(CINC)

#	debug
CDEBUG			=	-g -fsanitize=address
CFLAGS			+=	$(CDEBUG)

# ============================ files ========================================= #

OBJS			:=	main.o
OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

VPATH			:=	src

# =========================== rules ========================================= #

NAME			=	minishell

all: modules $(NAME)

$(NAME): $(BIN_DIR) $(OBJS) $(MODULE_ARCHIVE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MODULE_ARCHIVE)

$(BIN_DIR):
	mkdir $(BIN_DIR)

modules:
	make -C src/prompt/
	make -C src/core/

$(BIN_DIR)%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) bin

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re modules
-include $(DEPS)
