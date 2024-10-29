# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 00:51:08 by tle-dref          #+#    #+#              #
#    Updated: 2024/10/29 01:01:57 by tle-dref         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = push_swap

# Dossiers
SRCS_DIR = srcs
PRINTF_DIR = ft_printf
INC_DIR = .  # Dossier contenant push_swap.h

# Fichiers sources et objets
SRCS = $(addprefix $(SRCS_DIR)/, algo.c atol_scam.c cost.c cost2.c move.c parsing.c \
        push_swap.c push.c return.c reverse.c rotate.c swap.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c)
PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, ft_printf.c put_char_str.c put_hex.c put_nb.c)

OBJS = $(SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
