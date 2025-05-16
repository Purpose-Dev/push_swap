# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 10:19:39 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/05/16 10:33:08 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    DEBUG_FLAGS	= -g -O0 -DDEBUG
    DEBUGGER	= lldb
    LEAKS		= leaks --atExit --
else ifeq ($(UNAME_S), Linux)
    DEBUG_FLAGS	= -ggdb -O0 -DDEBUG
    DEBUGGER	= gdb --args
    LEAKS		= valgrind --leak-check=full
endif

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJ_DIR			= objs
DEBUG_DIR		= debug_objs

SRCS		= main.c comparator.c parsing.c sorting.c
OBJS		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
DEBUG_OBJS	= $(patsubst %.c, $(DEBUG_DIR)/%.o, $(SRCS))

HEADERS		= push_swap.h comparator.h parsing.h sorting.h

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(DEBUG_DIR):
	@mkdir -p $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I*.h -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

debug: $(DEBUG_DIR) $(DEBUG_OBJS)
	@echo "Debug build complete."
	@echo "Run with: $(DEBUGGER) ./$(NAME)"
	@echo "Debug build complete."

$(DEBUG_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I*.h -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(DEBUG_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug