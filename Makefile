# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:26:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/17 20:04:10 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names
NAME		=	push_swap
CHECKER		=	checker

# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INC_DIR)
DEBUG		=	-fsanitize=address -g  #TODO: check this!! and also check MMD Y MT pels fitxers .d?
#ifdef DEBUG
#    CFLAGS	+=	-g -fsanitize=address
#endif

# Directories
INC_DIR		=	includes
SRC_DIR		=	src
STACK_DIR	=	$(SRC_DIR)/stack
RULES_DIR	=	$(SRC_DIR)/rules
UTILS_DIR	=	$(SRC_DIR)/utils
TURK_DIR	=	$(SRC_DIR)/turk_algorithm
LIBFT_DIR	=	libft
OBJ_DIR		=	obj

# Create obj subdirectories #TODO: CHECK IF THIS IS A GOOD PRACTIE. I AM NOT USING THIS RIGHT NOW!!!!
OBJ_DIRS	=	$(OBJ_DIR) \
				$(OBJ_DIR)/stack \
				$(OBJ_DIR)/rules \
				$(OBJ_DIR)/utils \
				$(OBJ_DIR)/turk_algorithm

# TODO Headers
INCLUDES	=	$(INC_DIR)/libft.h \
				$(INC_DIR)/ft_printf_bonus.h \
				$(INC_DIR)/get_next_line.h \
				$(INC_DIR)/push_swap.h \
				$(INC_DIR)/stack.h \
				$(INC_DIR)/checker_bonus.h

# Source files
STACK_SRC	=	stack_manager.c stack_push_pop.c stack_min_max.c \
				stack_check_sorted.c stack_sort.c

RULES_SRC	=	rule_push.c rule_swap.c rule_rotate.c rule_reverse_rotate.c

UTILS_SRC	=	parse_arguments.c sequence_manager.c push_swap.c

TURK_SRC	=	calculate_moves.c best_move.c turk_algorithm.c

MAIN_SRC	=	main.c
CHECKER_SRC	=	checker_bonus.c

# Object files
STACK_OBJ	=	$(addprefix $(OBJ_DIR)/stack/, $(STACK_SRC:.c=.o))
RULES_OBJ	=	$(addprefix $(OBJ_DIR)/rules/, $(RULES_SRC:.c=.o))
UTILS_OBJ	=	$(addprefix $(OBJ_DIR)/utils/, $(UTILS_SRC:.c=.o))
TURK_OBJ	=	$(addprefix $(OBJ_DIR)/turk_algorithm/, $(TURK_SRC:.c=.o))
MAIN_OBJ	=	$(addprefix $(OBJ_DIR)/, $(MAIN_SRC:.c=.o))
CHECKER_OBJ	=	$(addprefix $(OBJ_DIR)/, $(CHECKER_SRC:.c=.o))

# All objects combined
OBJS		=	$(STACK_OBJ) $(RULES_OBJ) $(UTILS_OBJ) $(TURK_OBJ)
OBJS_ALL	=	$(STACK_OBJ) $(RULES_OBJ) $(UTILS_OBJ) $(TURK_OBJ) $(MAIN_OBJ)

# Library
LIBFT		=	$(LIBFT_DIR)/libft.a

# Colors for output
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

# Main targets
all: $(NAME)

bonus: $(CHECKER)

# Create necessary directories
$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(GREEN)Created directory: $@$(RESET)"

# Compile source files #TODO: flg pels includes MMD -MT??/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) | $(OBJ_DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# Build main executable
$(NAME): $(OBJS_ALL) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_ALL) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Built: $(NAME)$(RESET)"

# Build checker
$(CHECKER): $(OBJS) $(CHECKER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)
	@echo "$(GREEN)Built: $(CHECKER)$(RESET)"

# Build libft
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Built: libft$(RESET)"

# Clean targets
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)Cleaned object files$(RESET)"

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)Cleaned executables$(RESET)"

re: fclean all

# Development helpers
debug: CFLAGS += $(DEBUG)
debug: re

debug_bonus: CFLAGS +=  $(DEBUG)
debug_bonus: re bonus

norm:
	norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

.PHONY: all bonus clean fclean re debug debug_bonus norm

# Dependencies
-include $(OBJS:.o=.d)
