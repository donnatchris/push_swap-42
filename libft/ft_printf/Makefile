# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 18:14:25 by christophed       #+#    #+#              #
#    Updated: 2024/12/16 18:55:48 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################
## ARGUMENTS

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I includes/

SRC_DIR			= src
OBJ_DIR			= obj

#############################################################
## SOURCES

SRC_FILES		= ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putint_pf.c \
                  ft_putuint_pf.c ft_puthexamin_pf.c ft_puthexamaj_pf.c \
                  ft_check_address_pf.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re