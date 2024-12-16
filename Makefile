# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:21:20 by christophed       #+#    #+#              #
#    Updated: 2024/12/16 16:44:38 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
TARGET = bin/push_swap

# Répertoires
SRC_DIR = src
UTILS_DIR = utils
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

# Fichiers source et objets
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Options de compilation
CFLAGS = -Wall -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)/include

# Options de l'éditeur de liens
LDFLAGS = -L$(LIBFT_DIR) -lft

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS) $(LIBFT_DIR)/libft.a
    @mkdir -p $(dir $@)
    $(CC) $(OBJS) -o $@ $(LDFLAGS)

# Règle pour créer les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

# Règle pour compiler libft
$(LIBFT_DIR)/libft.a:
    $(MAKE) -C $(LIBFT_DIR)

# Règle pour nettoyer les fichiers générés
clean:
    rm -rf $(OBJ_DIR)
    $(MAKE) -C $(LIBFT_DIR) clean

# Règle pour nettoyer tout
fclean: clean
    rm -rf $(TARGET)
    $(MAKE) -C $(LIBFT_DIR) fclean

# Règle pour recompiler tout
re: fclean all

.PHONY: all clean fclean re