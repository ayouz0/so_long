# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 14:28:04 by aaitabde          #+#    #+#              #
#    Updated: 2025/01/24 10:08:51 by aaitabde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RESET_COLOR = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
CYAN = \033[1;36m
MAGENTA = \033[1;35m

CFLAGS = -Wall -fsanitize=address -Werror -Wextra

SRC = mandatory/error_utils.c mandatory/general_utils.c mandatory/main.c mandatory/map_utils.c mandatory/get_next_line/get_next_line.c\
	mandatory/get_next_line/get_next_line_utils.c mandatory/map_utils_1.c mandatory/so_long.c mandatory/game_running.c mandatory/make_moves.c

OBJ = ${SRC:.c=.o}

%.o:%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(GREEN)🎉✨ Build succeeded! $(RESET_COLOR)"
	@echo "$(CYAN)  Your program '$(NAME)' is ready to run.$(RESET_COLOR)"
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(YELLOW)To execute, run: ./$(NAME)$(RESET_COLOR)"

all : $(NAME)

clean : 
	@echo "$(RED)🧹 Cleaning up build files...$(RESET_COLOR)"
	@rm -f $(OBJ)
	@sleep 0.6 && clear
	@echo "$(GREEN)✨ Clean complete.$(RESET_COLOR)"

re : fclean all

fclean : clean
	@rm -f $(NAME)