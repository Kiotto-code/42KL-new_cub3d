# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2024/03/08 21:38:41 by etlaw             #+#    #+#              #
# #    Updated: 2024/03/20 15:22:49 by yichan           ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# NAME = cub3d

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I -g3 
# LDFLAGS = -fsanitize=address -g3
# MLX = -I /usr/X11/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit

# OBJS = obj/init.o \
# 	   obj/main.o \
# 	   obj/hooking.o \
# 	   obj/test.o \
# 	   obj/drawing.o \
# 	   obj/libft.o \
# 	   obj/raycast.o \

# all: $(NAME)

# re: fclean all
 
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(MLX) $(LDFLAGS)

# obj:
# 	mkdir obj

# obj/%.o: ./%.c | obj
# 	$(CC) -c $< -o $@ $(CFLAGS)

# clean:
# 	rm -rf obj

# fclean: clean
# 	rm -f $(NAME)

# .PHONY: all re clean fclean

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3
MLX = -I /usr/X11/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit
LIBFT_PATH = ./libft

# OBJS = obj/init.o \
# 	   obj/main.o \
# 	   obj/hooking.o \
# 	   obj/test.o \
# 	   obj/drawing.o \
# 	   obj/libft.o \
# 	   obj/raycast.o \

SRCS = $(wildcard *.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# all: $(NAME)
# 		make -C ${LIBFT_PATH}

# re: fclean all

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(MLX) $(LDFLAGS) -L${LIBFT_PATH} -lft

# obj:
# 	mkdir obj

# obj/%.o: ./%.c | obj
# 	$(CC) -c $< -o $@ $(CFLAGS)

# clean:
# 	rm -rf obj

# fclean: clean
# 	${MAKE} -C ${LIBFT_PATH} $@
# 	rm -f $(NAME)

# .PHONY: all re clean fclean

all			:	${NAME}

${NAME}		:	${OBJS}
				make -C ${LIBFT_PATH}
				${MLX_MAKE}
				$(CC) ${CFLAGS} ${MLXFLAGS} $^  -lft -L${LIBFT_PATH} ${MLX} -o $@
				@echo "The program name is $(RED)./$(NAME) $(RESET)"

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c ./includes/*.h ./Makefile 
					@mkdir -p $(@D)
					${CC} ${CFLAGS} ${MLXFLAGS2} -c $< -o $@
						
clean		:
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${OBJS_PATH}

fclean		: 	clean
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${NAME}

re			:	fclean all

.PHONY		:	clean fclean all re

