# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/11/15 19:17:29 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	fdf

SRC 	=	\
			draw.c			\
			init.c			\
			main.c			\


OBJS		=	$(SRC:.c=.o)

LIB			=	libft/
INC			=	Includes/
OBJS_DIR	=	objs/
SRCS_DIR	=	srcs/
SRCS_LIST	=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS_LIST	=	$(addprefix $(OBJS_DIR), $(OBJS))

#_Compilation_#

FLAG 		=	-Wall -Wextra #-Werror
MLX_FLAG	=	-lmlx -framework OpenGl -framework AppKit

all: $(NAME)

norm:
	@clear
	@norminette $(SRCS_LIST) $(INC)

#_Compilation_#

$(NAME):
	@make -C $(LIB)
	@gcc $(FLAG) -c $(SRCS_LIST) -I $(INC) -I $(LIB)
	@mkdir -p $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)
	@echo "\x1B[32m [ Created objs\x1B[32m ]\x1B[0m "
	@gcc $(FLAG) $(MLX_FLAG) $(OBJS_LIST) -I $(INC) -I $(LIB) $(LIB)libft.a -o $(NAME)
	@echo "\x1B[32m [ Created $@ executable √\x1B[32m ]\x1B[0m "

clean:
	@echo "\x1B[32m [ Clean... \x1B[32m ]\x1B[0m "
	@rm -f $(OBJS_LIST)
	@make clean -C $(LIB)

fclean: clean
	@echo "\x1B[32m [ Fclean... \x1B[32m ]\x1B[0m "
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
