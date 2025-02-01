# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 14:28:04 by aaitabde          #+#    #+#              #
#    Updated: 2025/02/01 18:03:20 by aaitabde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

RESET_COLOR = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
CYAN = \033[1;36m
MAGENTA = \033[1;35m

CFLAGS =  -g -fsanitize=address

SRC = mandatory/error_utils.c mandatory/general_utils.c mandatory/main.c mandatory/map_utils.c mandatory/get_next_line/get_next_line.c\
	mandatory/get_next_line/get_next_line_utils.c mandatory/map_utils_1.c mandatory/so_long.c mandatory/game_running.c mandatory/make_moves.c\
	mandatory/init_imgs.c mandatory/map_utils_2.c

SRCB = bonus/error_utils_bonus.c bonus/general_utils_bonus.c bonus/main_bonus.c bonus/map_utils_bonus.c bonus/get_next_line/get_next_line_bonus.c\
	bonus/get_next_line/get_next_line_utils_bonus.c bonus/map_utils_1_bonus.c bonus/so_long_bonus.c bonus/game_running_bonus.c bonus/make_moves_bonus.c\
	bonus/init_imgs_bonus.c bonus/map_utils_2_bonus.c bonus/move_enemy_bonus.c bonus/general_utils1_bonus.c bonus/move_enemy_bonus1.c
OBJ = ${SRC:.c=.o}

BOBJ = ${SRCB:.c=.o}

%.o:%.c mandatory/so_long.h bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(GREEN)🎉✨ Build succeeded! $(RESET_COLOR)"
	@echo "$(CYAN)  Your program '$(NAME)' is ready to run.$(RESET_COLOR)"
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(YELLOW)To execute, run: ./$(NAME)$(RESET_COLOR)"

$(BONUS) : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(GREEN)🎉✨ Build succeeded! $(RESET_COLOR)"
	@echo "$(CYAN)  Your program '$(BONUS)' is ready to run.$(RESET_COLOR)"
	@echo "$(MAGENTA)──────────────────────────────────────────────$(RESET_COLOR)"
	@echo "$(YELLOW)To execute, run: ./$(BONUS)$(RESET_COLOR)"

all : $(NAME)
bonus : $(BONUS)

clean : 
	@echo "$(RED)🧹 Cleaning up build files...$(RESET_COLOR)"
	@rm -f $(OBJ) $(BOBJ)
	@sleep 0.6 && clear
	@echo "$(GREEN)✨ Clean complete.$(RESET_COLOR)"

re : fclean all

fclean : clean
	@rm -f $(NAME)