# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:21:20 by christophed       #+#    #+#              #
#    Updated: 2024/12/16 16:23:38 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
TARGET = bin/push_swap

# Répertoires
SRC_DIR = src
UTILS_DIR = utils
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = lib

# Fichiers source et objets
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Options de compilation
CFLAGS = -Wall -Wextra -I$(INC_DIR)

# Options de l'éditeur de liens
LDFLAGS = -L$(LIB_DIR)

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
    @mkdir -p $(dir $@)
    $(CC) $(OBJS) -o $@ $(LDFLAGS)

# Règle pour créer les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
    rm -rf $(OBJ_DIR) $(TARGET)

# Règle pour nettoyer tout
fclean: clean
    rm -rf $(TARGET)

# Règle pour recompiler tout
re: fclean all

.PHONY: all clean fclean re