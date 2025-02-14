# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:26:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/12 11:37:59 by cmayne-p         ###   ########.fr        #
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

INCLUDES = $(INCLUDES_DIR)/libft.h $(INCLUDES_DIR)/ft_printf.h $(INCLUDES_DIR)/ft_printf_bonus.h

SRCS = main.c parse_arguments.c stack_manager.c stack_push_pop.c \
		rule_push.c rule_swap.c rule_rotate.c rule_reverse_rotate.c \
		stack_min_max.c stack_check_sorted.c sort.c \
		calculate_moves.c best_move.c movement_seq.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft printf $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS)  $(LIBFT) $(PRINTF) -o $(NAME)

libft:
	$(MAKE) bonus -C $(LIBFT_DIR)
	
printf:
	$(MAKE) bonus -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES) $(SRCS_BONUS)

.PHONY: all clean fclean re norm bonus bonus_clean libft printf
