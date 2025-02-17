# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:26:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/17 12:39:33 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES_DIR = includes
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR) -g #TODO: quitar flag para entregar

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = $(INCLUDES_DIR)/libft.h \
			$(INCLUDES_DIR)/ft_printf.h \
			$(INCLUDES_DIR)/ft_printf_bonus.h \
			$(INCLUDES_DIR)/get_next_line.h \
			$(INCLUDES_DIR)/push_swap.h \
			$(INCLUDES_DIR)/stack.h


SRCS = stack_manager.c stack_push_pop.c stack_min_max.c stack_check_sorted.c \
		rule_push.c rule_swap.c rule_rotate.c rule_reverse_rotate.c \
		parse_arguments.c push_swap.c sort.c \
		calculate_moves.c best_move.c sequence_manager.c turk_algorithm.c \
		radix_algorithm.c
OBJS = $(SRCS:.c=.o)

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
SRCS_BONUS = checker/checker.c $(GNL)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) main.c $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF): $(LIBFT)
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PRINTF) -o checker_mine

norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES) $(SRCS_BONUS)

.PHONY: all clean fclean re norm bonus bonus_clean
