# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/10/11 11:45:23 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR				=	ar -rcs
CC				=	cc

ROOT_DIR		=	../../
BIN_DIR			=	$(ROOT_DIR)bin/
INC_DIR			=	$(ROOT_DIR)inc/
MODULE_NAME		=	env

# ============================ libft ========================================= #

LIBFT_DIR		=	$(ROOT_DIR)lib/libft/
LIBFT			=	$(LIBFT_DIR)libft.a

# ============================ cflags ======================================== #

CFLAGS			:=	-Wall -Wextra -Werror

#	includes
CINC			+=	-I$(LIBFT_DIR) 
CINC			+=	-I$(INC_DIR) 
CFLAGS			+=	$(CINC)

#	debug
CDEBUG			=	-g -fsanitize=address
CFLAGS			+=	$(CDEBUG)

#	dependencies
CFLAGS			+=	-MMD

# ============================ files ========================================= #

OBJS			:=	mock.o
OBJS			:=	$(addprefix $(MODULE_NAME)_, $(OBJS))
OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

# ============================ rules ========================================= #

NAME			=	$(BIN_DIR)$(MODULE_NAME).a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BIN_DIR)$(MODULE_NAME)_%.o: %.c $(LIBFT) Makefile
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all
-include $(DEPS)
