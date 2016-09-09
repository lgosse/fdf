# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 16:47:05 by lgosse            #+#    #+#              #
#    Updated: 2016/04/19 14:28:35 by lgosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	fdf.c \
			fdf_init.c \
			fdf_init2.c \
			draw_hud1.c \
			draw_hud2.c \
			draw_hud3.c \
			draw.c \
			draw_line.c \
			init_hooks.c \
			hooks.c \
			modify_fdf.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = fdf

SRC_PATH = src/
LIB_PATH = libft/includes/
OBJ_PATH = obj/

SRC_LIB = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = -Llibft -lmlx -framework OpenGL -framework AppKit
LDLIBS = -lft

all:$(NAME)

$(NAME):$(OBJ)
	make -C libft/ -j 8
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32mCompilation done !\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

clean:
	@echo "\033[31mCleaned following files :\033[0m"
	@make -C libft/ clean
	@rm -fv $(OBJ)
	@rm -rfv $(OBJ_PATH)
	@echo "\033[32mClean objects done !\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@echo "\033[32mClean executable done !\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
