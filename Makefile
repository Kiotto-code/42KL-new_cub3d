# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 15:16:52 by yichan            #+#    #+#              #
#    Updated: 2024/04/07 00:04:10 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -fsanitize=address -g3
# CFLAGS += -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
SRCS_PATH	= ./srcs/**
OBJS_PATH	= ./objs
LIBFT_PATH	= ./libft

SRCS 		= $(shell find ./srcs -name "*.c")
# OBJS		= ${patsubst ${SRCS_PATH}/%.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS 		= $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
# OBJS		= ${patsubst %.c, ${OBJS_PATH}/%.o, ${notdir ${SRCS}}}
# OBJS		= ${patsubst %.c, ${OBJS_PATH}/%.o,  ${SRCS}}


RESET		=	\033[0m
GREEN		=	\033[38;5;46m
WHITE		=	\033[38;5;15m
GREY		=	\033[38;5;8m
ORANGE		=	\033[38;5;202m
RED			=	\033[38;5;160m

all			:	${NAME}

${NAME}		:	${OBJS}
				make -C mlx
				make -C ${LIBFT_PATH}
				$(CC) ${CFLAGS} ${MLXFLAGS} $^  -lft -L${LIBFT_PATH} -o $@
				@echo "The program name is $(RED)./$(NAME) $(RESET)"

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c ./includes/*.h ./Makefile | ${OBJS_PATH}
					${CC} ${CFLAGS} ${MLXFLAGS2} -c $< -o $@
					@echo "The program name is $(GREEN)./$(NAME) $(RESET)"

$(OBJS_PATH)			:
							mkdir -p $(OBJS_PATH)
						
clean		:
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${OBJS_PATH}

fclean		: 	clean
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${NAME}

re			:	fclean all

.PHONY		:	clean fclean all re

