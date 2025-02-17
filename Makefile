# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:26:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/17 17:30:27 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR) -g #TODO: quitar flag para entregar

INCLUDES_DIR = includes
LIBFT_DIR = libft
SRCS_DIR = src
RULES_DIR = $(SRCS_DIR)/rules
STACK_DIR = $(SRCS_DIR)/stack
UTILS_DIR = $(SRCS_DIR)/utils
TURK_DIR = $(SRCS_DIR)/turk_algorithm
OBJS_DIR = objs

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = $(INCLUDES_DIR)/libft.h \
			$(INCLUDES_DIR)/ft_printf_bonus.h \
			$(INCLUDES_DIR)/get_next_line.h \
			$(INCLUDES_DIR)/push_swap.h \
			$(INCLUDES_DIR)/stack.h \
			$(INCLUDES_DIR)/checker_bonus.h

STACK_SRCS = $(STACK_DIR)/stack_manager.c \
			$(STACK_DIR)/stack_push_pop.c \
			$(STACK_DIR)/stack_min_max.c \
			$(STACK_DIR)/stack_check_sorted.c \
			$(STACK_DIR)/stack_sort.c

RULES_SRCS = $(RULES_DIR)/rule_push.c \
			$(RULES_DIR)/rule_swap.c \
			$(RULES_DIR)/rule_rotate.c \
			$(RULES_DIR)/rule_reverse_rotate.c

UTILS_SRCS = $(UTILS_DIR)/parse_arguments.c \
			$(UTILS_DIR)/push_swap.c \
			$(UTILS_DIR)/sequence_manager.c

TURK_SRCS = $(TURK_DIR)/calculate_moves.c \
			$(TURK_DIR)/best_move.c \
			$(TURK_DIR)/turk_algorithm.c

SRCS = main.c $(STACK_SRCS) $(RULES_SRCS) $(UTILS_SRCS) $(TURK_SRCS)
OBJS = $(SRCS:.c=.o) #TODO en la carpeta que toca

SRCS_BONUS = checker_bonus.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) main.c $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) $(LIBFT) -o checker

norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES) $(SRCS_BONUS)

.PHONY: all clean fclean re norm bonus
