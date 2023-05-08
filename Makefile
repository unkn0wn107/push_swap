# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/05/08 23:37:56 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj

SRC = ${SRC_DIR}/push_swap.c
H = ${SRC_DIR}/push_swap.h
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft
LIBFT_HEADER = libft/libft.h
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror -g3
OBJ_FLAGS = ${CFLAGS} -I$(LIBFT) -I$(SRC_DIR)
CC = gcc

all:			${NAME}

${NAME}:		${LIBFT} mkdir ${OBJ} $(LIBFT_HEADER) $(H)
			${CC} ${CFLAGS} ${OBJ} -o $@ ${LIBFT_FLAGS}

${LIBFT}:		FORCE;
			$(MAKE_LIBFT)

FORCE: ;

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_HEADER) $(H)
			$(CC) $(OBJ_FLAGS) -o $@ -c $<

mkdir:
			mkdir -p $(OBJ_DIR)

clean:
		$(MAKE_LIBFT) $@
		rm -r ${OBJ_DIR}
		find . -name "*.gch" -delete

fclean:	clean
		$(MAKE_LIBFT) $@
		find . -name "${NAME}" -delete

re:		fclean all

.PHONY:	all clean fclean re
