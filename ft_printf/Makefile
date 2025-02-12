# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/27 20:51:10 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES_DIR = ../includes
LIBFT_DIR = ../libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = $(INCLUDES_DIR)/ft_printf.h $(INCLUDES_DIR)/libft.h $(INCLUDES_DIR)/ft_printf_bonus.h

SRCS = ft_printf.c write_types.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) Makefile
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean bonus_clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# --------------- BONUS --------------------
SRCS_BONUS = ft_printf_bonus.c write_types_bonus.c \
			flags_manager_bonus.c parse_types_bonus.c parse_precision_bonus.c \
			parse_flags_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

bonus: $(OBJS_BONUS) $(LIBFT) Makefile
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)

bonus_clean:
	rm -rf $(OBJS_BONUS)
# --------------------------------------------


norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES) $(SRCS_BONUS)

.PHONY: all clean fclean re norm bonus bonus_clean
