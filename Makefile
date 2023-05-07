# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/05/08 01:07:06 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj

LIBFT = libft
LIBFT_HEADERS = libft/libft.h
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror -pipe
OBJ_FLAGS = ${CFLAGS} -I$(LIBFT) -I$(SRC_DIR)
CC = gcc

all:			${LIBFT} ${NAME}

${NAME}:		${LIBFT} ${OBJ_SRV}
			${CC} ${CFLAGS} ${OBJ_SRV} -o $@ ${LIBFT_FLAGS}

${LIBFT}:
			$(MAKE_LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_HEADERS)
			mkdir $(OBJ_DIR)
			$(CC) $(OBJ_FLAGS) -o $@ -c $<

clean:
		$(MAKE_LIBFT) $@
		rm -r ${OBJ_DIR}
		find . -name "*.gch" -delete

fclean:	clean
		$(MAKE_LIBFT) $@
		find . -name "${NAME}" -delete

re:		fclean all

.PHONY:	all clean fclean re
