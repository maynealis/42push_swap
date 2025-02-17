# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 16:18:25 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/17 15:18:34 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES_DIR = ../includes
OBJS_DIR = objs

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR)

INCLUDES = $(INCLUDES_DIR)/libft.h \
	$(INCLUDES_DIR)/ft_printf_bonus.h \
	$(INCLUDES_DIR)/get_next_line.h
	
LIBFT_SRCS = ft_isspace.c \
	ft_isupper.c \
	ft_islower.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_numlen.c \
	ft_uitoa_base.c \
	ft_ultoa_base.c
		
LIBFT_LIST_SRCS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

PRINTF_SRCS = ft_printf_bonus.c \
	ft_printf_flags_manager_bonus.c \
	ft_printf_parse_flags_bonus.c \
	ft_printf_parse_precision_bonus.c \
	ft_printf_parse_types_bonus.c \
	ft_printf_write_types_bonus.c
	
GNL_SRCS = get_next_line.c get_next_line_utils.c


SRCS = $(LIBFT_SRCS) $(LIBFT_LIST_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c $(INCLUDES) Makefile | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES) Makefile
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(INCLUDES)

.PHONY: all clean fclean re norm bonus
