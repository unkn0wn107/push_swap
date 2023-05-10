# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/05/10 01:52:34 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

SRC = push_swap.c
SRCS = ${SRC_DIR}/stack_adapter.c \
	${SRC_DIR}/stack_utils.c ${SRC_DIR}/stack_swap_push.c \
	${SRC_DIR}/parser.c ${SRC_DIR}/error.c
H = ${SRC_DIR}/push_swap.h
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_TEST = ${TEST_DIR}/test.c \
	${TEST_DIR}/stack_swap_push.test.c
H_TEST = ${TEST_DIR}/test.h
OBJ_TEST = $(SRC_TEST:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft
LIBFT_HEADER = libft/libft.h
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror -g3
OBJ_FLAGS = ${CFLAGS} -I$(LIBFT) -I$(SRC_DIR)
CC = gcc

all:	${NAME}

${NAME}:		${LIBFT} mkdir ${OBJ} ${OBJS} $(LIBFT_HEADER) $(H)
			${CC} ${CFLAGS} ${OBJ} ${OBJS} -o $@ ${LIBFT_FLAGS}

${LIBFT}:		FORCE;
			$(MAKE_LIBFT)

FORCE: ;

$(OBJ_DIR)/%.test.o:	$(TEST_DIR)/%.c $(LIBFT_HEADER) $(H) $(H_TEST)
			$(CC) $(OBJ_FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(LIBFT_HEADER) $(H)
			$(CC) $(OBJ_FLAGS) -o $@ -c $<

# ${OBJ}: 		$@/%.c $(LIBFT_HEADER) $(H)
# 			$(CC) $(OBJ_FLAGS) -o $@ -c $<

# ${OBJS}: 		$@/%.c $(LIBFT_HEADER) $(H)
# 			$(CC) $(OBJ_FLAGS) -o $@ -c $<

unit-test:		${LIBFT} mkdir ${OBJ_TEST} ${OBJS} $(LIBFT_HEADER) $(H) $(H_TEST)
			${CC} ${CFLAGS} ${OBJ_TEST} ${OBJS} -o $@ ${LIBFT_FLAGS}

# ${OBJ_TEST}: 	$(LIBFT_HEADER) $(H) $(H_TEST)
# 			$(CC) $(OBJ_FLAGS) -o $@ -c $<

mkdir:
			mkdir -p $(OBJ_DIR)

check:
		norminette

clean:
		$(MAKE_LIBFT) $@
		rm -r ${OBJ_DIR}
		find . -name "*.gch" -delete

fclean:	clean
		$(MAKE_LIBFT) $@
		find . -name "${NAME}" -delete

re:		fclean all

.PHONY:	all clean fclean re
