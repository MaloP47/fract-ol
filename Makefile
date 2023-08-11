# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:35:40 by mpeulet           #+#    #+#              #
#    Updated: 2023/07/08 15:41:16 by mpeulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors / base 16 / Bright

DEF_COLOR		= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

#Colors / Perso / Bright

ORANGE			= \033[38;5;214m

#Mlx42

MLX_DIR			= mlx42/
MLX_NAME		= libmlx.a
MLX				= $(MLX_DIR)$(MLX_NAME)

#Libft

LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Variables

NAME			= fractol
CC				= cc
FLAGS			= -Wall -Werror -Wextra
RM				= rm -f
AR				= ar rcs
NORM			= ./includes\
					./libft/include/\
					./libft/src_lib
INCLUDE			= 	-I ./includes/\
					-I ./libft/include/\
					-I ./mlx42/

#Sources

OBJ_DIR_F 		= obj/
SRC_DIR_F		= src/
SRC_FUNCTIONS_F	= close_program colors events extra_keyboard_actions \
					full_default_init main movements_in_window parsing \
					render utils_init fractals/burning_ship fractals/julia \
					fractals/lyapunov fractals/mandelbrot \

FRACT_SRC		= $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(SRC_FUNCTIONS_F)))
FRACT_OBJ		= $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(SRC_FUNCTIONS_F)))

IFMAKE_DIR_F	= .cache_exists

#instructions

all:			$(MLX) $(LIBFT) $(NAME)

$(IFMAKE_DIR_F):
					@mkdir -p $(OBJ_DIR_F)
					@mkdir -p $(OBJ_DIR_F)fractals/

$(MLX):
					@echo "Getting MinilibX ready"
					@make -sC $(MLX_DIR)

$(LIBFT):
					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR_F)fractals/%.o: $(SRC_DIR_F)fractals/%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(FRACT_OBJ)
					@echo "Compiling fractol..."
					@$(CC) $(FLAGS) -o $(NAME) $(FRACT_OBJ) $(MLX) $(LIBFT) $(INCLUDE) -lXext -lX11 -lm
					@echo "Fractol ready."

bonus:			all

clean:
					@echo "Removing object files"
					@rm -rf $(OBJ_DIR_F)
					@make clean -C $(MLX_DIR)
					@make clean -C $(LIBFT_DIR)
					
fclean:			clean
					@echo "Removing fractol..."
					@rm -f $(NAME)
					@rm -f $(LIBFT_DIR)$(LIBFT_NAME)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for fractol$(DEF_COLOR)"

norm:
					@norminette $(SRC_DIR_F) $(NORM) $(LIBFT_DIR) | grep -v Norme -B1 || true
					@echo "Norminet the cat says : $(RED)M$(ORANGE)e$(YELLOW)o$(GREEN)w$(CYAN) !$(BLUE)!$(MAGENTA)!$(DEF_COLOR)"

.PHONY: all re clean fclean norm bonus