# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:21:20 by christophed       #+#    #+#              #
#    Updated: 2025/01/06 15:32:08 by chdonnat         ###   ########.fr        #
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