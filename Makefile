# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:59:02 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/07/28 10:52:11 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER_NAME	= checker

SRCS_DIR		= ./srcs
INC_DIR			= ./includes
OBJ_DIR			= objs
DEBUG_OBJ_DIR	= debug_objs
LIBFT_DIR		= libs/libft
LIBFT			= $(LIBFT_DIR)/libft.a

SRCS_FILES		= misc/comparator.c misc/index.c misc/parse.c misc/utils.c \
					operations/operations_0.c operations/operations_1.c operations/operations_2.c \
					sorting/cost_and_execute_utils.c sorting/cost_and_execute_utils_1.c \
					sorting/sort_large.c sorting/sort_small_0.c sorting/sort_small_1.c \
					sorting/target_position_utils.c stack/stack_0.c stack/stack_1.c

COMMON_SRCS_FILES	= misc/comparator.c misc/index.c misc/parse.c misc/utils.c \
						operations/operations_0.c operations/operations_1.c operations/operations_2.c \
						sorting/cost_and_execute_utils.c sorting/cost_and_execute_utils_1.c \
						sorting/sort_large.c sorting/sort_small_0.c sorting/sort_small_1.c \
						sorting/target_position_utils.c stack/stack_0.c stack/stack_1.c

CHECKER_SPECIFIC_SRCS   = misc/checker_utils.c checker.c

SRCS			= $(addprefix $(SRCS_DIR)/, $(COMMON_SRCS_FILES) main.c)
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRCS))

CHECKER_SRCS	= $(addprefix $(SRCS_DIR)/, $(COMMON_SRCS_FILES) $(CHECKER_SPECIFIC_SRCS))
CHECKER_OBJS	= $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.o, $(CHECKER_SRCS))
CHECKER_DEPS	= $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.d, $(CHECKER_SRCS))

DEBUG_OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(DEBUG_OBJ_DIR)/%.o, $(SRCS))
DEBUG_DEPS		= $(patsubst $(SRCS_DIR)/%.c, $(DEBUG_OBJ_DIR)/%.d, $(SRCS))

CC           = cc
RM           = rm -f
CFLAGS        = -Wall -Wextra -Werror -I$(INC_DIR) -MMD -MP

HEADERS_FILENAMES = push_swap.h comparator.h parsing.h sorting.h checker.h
HEADERS_PATHS = $(addprefix $(INC_DIR)/, $(HEADERS_FILENAMES))

all: $(NAME)

bonus: $(CHECKER_NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!$(NO_COLOR)"

$(CHECKER_NAME): $(OBJ_DIR) $(LIBFT) $(CHECKER_OBJS)
	@echo "$(GREEN)Compiling $(CHECKER_NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER_NAME)
	@echo "$(GREEN)$(CHECKER_NAME) successfully compiled!$(NO_COLOR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEBUG_OBJ_DIR):
	@mkdir -p $(DEBUG_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS_PATHS)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(NO_COLOR)"
	@make -C $(LIBFT_DIR) -j
	@echo "$(GREEN)libft successfully compiled!$(NO_COLOR)"

debug: $(DEBUG_OBJ_DIR) $(LIBFT) $(DEBUG_OBJS)
	@echo "$(BLUE)Compiling in debug mode...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(DEBUG_OBJS) $(LIBFT) -o $(NAME)_debug
	@echo "$(BLUE)Debug build complete.$(NO_COLOR)"
	@echo "Run with: $(DEBUGGER) ./$(NAME)_debug"

$(DEBUG_OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS_PATHS)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< in debug mode...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

leaks: $(NAME)_debug
	@echo "$(BLUE)Checking for memory leaks...$(NO_COLOR)"
	@$(LEAKS) ./$(NAME)_debug 3 1 2 5 4

clean:
	@echo "$(RED)Removing object files...$(NO_COLOR)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(DEBUG_OBJ_DIR)
	@$(RM) -f $(OBJ_DIR)/*.d $(DEBUG_OBJ_DIR)/*.d

fclean: clean
	@echo "$(RED)Removing executables...$(NO_COLOR)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) -f $(NAME)
	@$(RM) -f $(NAME)_debug
	@$(RM) -f $(CHECKER_NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)--- Testing push_swap ---$(NO_COLOR)"
	@echo "$(BLUE)Test with 5 numbers: $(NO_COLOR)"
	@./$(NAME) 3 1 2 5 4
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker_linux "$$ARG"
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker_linux "$$ARG"
	@echo ""
	@echo "$(BLUE)--- Tests complete ---$(NO_COLOR)"

norm:
	@echo "$(YELLOW)Checking norm...$(NO_COLOR)"
	@norminette $(SRCS) $(HEADERS_PATHS) $(LIBFT_DIR)

.PHONY: all bonus clean fclean re debug leaks test norm