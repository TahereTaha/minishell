# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/10/16 09:24:50 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR				=	ar -rcs
CC				=	cc
RM				=	rm -rf

BIN_DIR			=	bin/
INC_DIR			=	inc/

# ============================ libs ========================================== #

#	libft
LIBFT_DIR		=	$(ROOT_DIR)libs/libft/
LIBFT			=	$(LIBFT_DIR)libft.a
LIBS			:=	$(LIBFT)

#	readline
#  == THINGS ==  #

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

all: libs $(BIN_DIR) modules $(NAME)

libs:
	git submodule init
	git submodule update
	make -C $(LIBFT_DIR) bonus


$(BIN_DIR):
	mkdir $(BIN_DIR)

modules:
	make -C src/prompt/
	make -C src/core/

$(NAME): $(OBJS) $(MODULE_ARCHIVE) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MODULE_ARCHIVE) $(LIBS)

$(BIN_DIR)%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) bin
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re modules libs
-include $(DEPS)
