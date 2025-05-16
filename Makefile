# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 10:19:39 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/05/16 10:37:15 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

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

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEBUG_DIR):
	@mkdir -p $(DEBUG_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)libft successfully compiled!$(RESET)"

debug: $(DEBUG_DIR) $(LIBFT) $(DEBUG_OBJS)
	@echo "$(BLUE)Compiling in debug mode...$(RESET)"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(DEBUG_OBJS) $(LIBFT) -o $(NAME)_debug
	@echo "$(GREEN)Debug build complete.$(RESET)"
	@echo "$(YELLOW)Run with: $(DEBUGGER) ./$(NAME)_debug$(RESET)"

$(DEBUG_DIR)/%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling $< in debug mode...$(RESET)"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

leaks: $(NAME)
	@echo "$(BLUE)Checking for memory leaks...$(RESET)"
	@$(LEAKS) ./$(NAME) 3 1 2 5 4

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(DEBUG_DIR)

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) -f $(NAME)
	@$(RM) -f $(NAME)_debug

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Test with 5 numbers: $(RESET)"
	@./$(NAME) 3 1 2 5 4
	@echo "$(BLUE)Test with 100 random numbers: $(RESET)"
	@ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./$(NAME) $ARG | wc -l

norm:
	@echo "$(BLUE)Checking norm...$(RESET)"
	@norminette $(SRCS) $(HEADERS) $(LIBFT_DIR)

.PHONY: all clean fclean re debug leaks test norm
