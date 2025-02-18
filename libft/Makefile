# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 16:18:25 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/18 15:21:24 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library
NAME	=	libft.a

# Compiler and flags
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I$(INC_DIR) -MMD -MP
DEBUG	=	-g -fsanitize=address

# Directories
INC_DIR	=	../includes
OBJ_DIR	=	objs

INCLUDES	=	$(INC_DIR)/libft.h \
				$(INC_DIR)/ft_printf_bonus.h \
				$(INC_DIR)/get_next_line.h
	
LIBFT_SRCS	=	ft_isspace.c \
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

LIBFT_LIST_SRCS	=	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c

PRINTF_SRCS	=	ft_printf_bonus.c \
				ft_printf_flags_manager_bonus.c \
				ft_printf_parse_flags_bonus.c \
				ft_printf_parse_precision_bonus.c \
				ft_printf_parse_types_bonus.c \
				ft_printf_write_types_bonus.c
	
GNL_SRCS				=	get_next_line.c get_next_line_utils.c

GNL_MULT_FILES_SRCS	=	get_next_line_bonus.c get_next_line_utils.c


LIBFT_OBJS		=	$(addprefix $(OBJ_DIR)/, $(LIBFT_SRCS:.c=.o))
LIBFT_LIST_OBJS	=	$(addprefix $(OBJ_DIR)/, $(LIBFT_LIST_SRCS:.c=.o))
PRINTF_OBJS		=	$(addprefix $(OBJ_DIR)/, $(PRINTF_SRCS:.c=.o))
GNL_OBJS		=	$(addprefix $(OBJ_DIR)/, $(GNL_SRCS:.c=.o))
GNL_MULT_FILES_OBJS		=	$(addprefix $(OBJ_DIR)/, $(GNL_MULT_FILES_SRCS:.c=.o))

SRCS = $(LIBFT_SRCS) $(LIBFT_LIST_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)
ALL_SRCS = $(LIBFT_SRCS) $(LIBFT_LIST_SRCS) $(PRINTF_SRCS) $(GNL_SRCS) $(GNL_MULT_FILES_SRCS)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
ALL_OBJS = $(addprefix $(OBJ_DIR)/, $(ALL_SRCS:.c=.o))


# Colors
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m


# ----------------- Targets -----------------
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Created directory: $(OBJ_DIR)$(RESET)"

$(OBJ_DIR)/%.o:%.c  Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@ar rcs $(NAME) $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@echo "$(GREEN)Built: $(NAME)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Cleanded object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleanded library$(RESET)"

re: fclean all

debug: CFLAGS += $(DEBUG)
debug: re

norm:
	norminette $(LIBFT_SRCS) $(LIBFT_LIST_SRCS) $(PRINTF_SRCS) $(GNL_SRCS) $(GNL_MULT_FILES_SRCS) $(INCLUDES)

.PHONY: all clean fclean re norm

# Include generated dependency files
-include $(ALL_OBJS:.o=.d)
