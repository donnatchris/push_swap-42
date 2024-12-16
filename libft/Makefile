# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:29:32 by christophed       #+#    #+#              #
#    Updated: 2024/12/16 18:26:42 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################
## ARGUMENTS

NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I include/ -I ft_printf/include/

SRC_DIR			= src
OBJ_DIR			= obj
FT_PRINTF_DIR	= ft_printf

#############################################################
## SOURCES

SRC_FILES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c

BONUS_FILES		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

BONUS_SRC		= $(addprefix $(SRC_DIR)/, $(BONUS_FILES))
BONUS_OBJ		= $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_DIR)/libftprintf.a
	ar rcs $(NAME) $(OBJ) $(FT_PRINTF_DIR)/libftprintf.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

$(FT_PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus