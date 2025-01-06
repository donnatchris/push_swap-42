# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:21:20 by christophed       #+#    #+#              #
#    Updated: 2025/01/06 15:26:50 by chdonnat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# arguments
NAME =				push_swap
BONUS_NAME =		checker
CC =				gcc
CFLAGS =			-Wall -Werror -Wextra
INCLUDES =			-I $(HEADER_DIR)/

# directories
SRC_DIR =			src
UTILS_DIR =			utils
HEADER_DIR =		includes
OBJ_DIR =			obj

BONUS_DIR =			bonus
BONUS_OBJ_DIR = 	obj_bonus

LIBFT_DIR =			libft
LIBFT =				libft/libft.a

# utils
RM = 				rm -rf

# sources and objects
SRC =				\
					$(SRC_DIR)/load_and_clear.c \
					$(SRC_DIR)/push_functions.c $(SRC_DIR)/rotate_functions.c \
					$(SRC_DIR)/reverse_rotate_functions.c $(SRC_DIR)/sort.c \
					$(SRC_DIR)/sort_utils.c $(SRC_DIR)/swap_functions.c \
					$(SRC_DIR)/variable_initializers.c

OBJ =				$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

UTILS_SRC =			\
					$(UTILS_DIR)/dclst1.c $(UTILS_DIR)/dclst2.c \
					$(UTILS_DIR)/dclst3.c $(UTILS_DIR)/dclst4.c \
					$(UTILS_DIR)/error_manager.c $(UTILS_DIR)/ft_atoi_long.c

UTILS_OBJ =			$(UTILS_SRC:$(UTILS_DIR)/%.c=$(OBJ_DIR)/$(UTILS_DIR)/%.o)

MAIN_SRC =			$(SRC_DIR)/main.c
OBJ_MAIN =			$(MAIN_SRC:$(SRC_DIR)/main.c=$(OBJ_DIR)/$(SRC_DIR)/main.o)

BONUS_SRC =			\
					$(BONUS_DIR)/checker.c \
					$(BONUS_DIR)/push_quiet.c $(BONUS_DIR)/swap_quiet.c \
					$(BONUS_DIR)/reverse_rotate_quiet.c $(BONUS_DIR)/rotate_quiet.c

BONUS_OBJ =			$(BONUS_SRC:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

BONUS_MAIN_SRC =	$(BONUS_DIR)/main.c
BONUS_OBJ_MAIN =	$(BONUS_MAIN_SRC:$(BONUS_DIR)/main.c=$(BONUS_OBJ_DIR)/main.o)

# rules and dependencies			
all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_MAIN) $(OBJ) $(UTILS_OBJ)
					$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ) $(UTILS_OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR) all
					
$(OBJ_DIR)/$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
					
$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
				
$(OBJ_DIR)/$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

bonus:				$(BONUS_NAME)

$(BONUS_NAME):		$(LIBFT) $(BONUS_OBJ_MAIN) $(BONUS_OBJ) $(OBJ) $(UTILS_OBJ)
					$(CC) $(CFLAGS) $(BONUS_OBJ_MAIN) $(OBJ) $(UTILS_OBJ) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)/main.o: $(BONUS_DIR)/main.c
					@mkdir -p $(BONUS_OBJ_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
			
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
					@mkdir -p $(BONUS_OBJ_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BONUS_OBJ_DIR)/$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
				
$(BONUS_OBJ_DIR)/$(OBJ_DIR)/$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

				
clean:
					make -C $(LIBFT_DIR) clean
					$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_DIR) fclean
					$(RM) $(NAME) $(BONUS_NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re

# # executable name
# TARGET = push_swap
# BONUS_TARGET = checker

# # directories
# OBJ_DIR = obj
# OBJ_DIR_MAIN = $(OBJ_DIR)/main
# OBJ_DIR_BONUS = $(OBJ_DIR)/bonus
# INC_DIR = includes
# LIBFT_DIR = libft
# BONUS_DIR = bonus

# # src and obj files
# MAIN = $(SRC_DIR)/main.c
# BONUS_MAIN = $(BONUS_DIR)/main.c
# SRCS = load_and_clear.c push_functions.c reverse_rotate_functions.c rotate_functions.c sort_utils.c sort.c swap_functions.c variable_initializers.c dclst1.c dclst2.c dclst3.c dclst4.c error_manager.c ft_atoi_long.c
# BONUS_SRCS = checker.c push_quiet.c reverse_rotate_quiet.c rotate_quiet.c swap_quiet.c

# OBJS = $(patsubst %.c, $(OBJ_DIR_MAIN)/%.o, $(notdir $(SRCS)))
# BONUS_OBJS = $(patsubst %.c, $(OBJ_DIR_BONUS)/%.o, $(notdir $(BONUS_SRCS)))
# MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR_MAIN)/%.o, $(notdir $(MAIN)))
# BONUS_MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR_BONUS)/%.o, $(notdir $(BONUS_MAIN)))

# # comilation options
# CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes

# # compiler
# CC = gcc

# # options
# LDFLAGS = -L$(LIBFT_DIR) -lft

# # rules
# all: $(TARGET)

# $(TARGET): $(OBJS) $(MAIN_OBJ) $(LIBFT_DIR)/libft.a
# 	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# bonus: $(BONUS_TARGET)

# $(BONUS_TARGET): $(BONUS_OBJS) $(BONUS_MAIN_OBJ) $(LIBFT_DIR)/libft.a
# 	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# $(OBJ_DIR_MAIN)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR_MAIN)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_MAIN)/%.o: $(UTILS_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR_MAIN)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR_BONUS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR_BONUS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_BONUS)/%.o: $(UTILS_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR_BONUS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT_DIR)/libft.a:
# 	$(MAKE) -C $(LIBFT_DIR)

# clean:
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	rm -f $(TARGET) $(BONUS_TARGET)

# re: fclean all

# .PHONY: all bonus clean fclean re
