# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/10/15 18:39:06 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR				=	ar -rcs
CC				=	cc

ROOT_DIR		=	../../
LIBS_DIR		=	$(ROOT_DIR)libs/
BIN_DIR			=	$(ROOT_DIR)bin/
INC_DIR			=	$(ROOT_DIR)inc/
MODULE_NAME		=	core

# ============================ cflags ======================================== #

LIBFT_DIR		=	$(LIBS_DIR)libft/

# ============================ cflags ======================================== #

CFLAGS			:=	-Wall -Wextra -Werror

#	includes
CINC			+=	-I$(INC_DIR) 
CINC			+=	-I$(LIBFT_DIR) 
CFLAGS			+=	$(CINC)

#	debug
CDEBUG			=	-g -fsanitize=address
CFLAGS			+=	$(CDEBUG)

#	dependencies
CFLAGS			+=	-MMD

# ============================ files ========================================= #

OBJS			:=	main.o			\
					tokenizer.o
OBJS			:=	$(addprefix $(MODULE_NAME)_, $(OBJS))
OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

# ============================ rules ========================================= #

NAME			=	$(BIN_DIR)$(MODULE_NAME).a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BIN_DIR)$(MODULE_NAME)_%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
-include $(DEPS)
