NAME	:= libft.a
DEBUG	:= debugrun
CC		:= gcc
AR		:= ar
CFLAGS	:= -Wall -Werror -Wextra -g3
# CFLAGS	+= -fsanitize=address -g3
ARFLAGS	:= rcs
RM		:= rm -rf
# DEBUG	:= ${ARGS}

INCLUDES	= ./includes
SRC_PATH	:= ./srcs/**
OBJ_PATH	:= ./obj

# UNAME := $(shell uname)
# ifeq ($(UNAME), Linux)
# 	MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
# 	MLXFLAGS2	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
# endif
# ifeq ($(UNAME), Darwin)
# 	MLXFLAGS	= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -Imlx
# 	MLXFLAGS2	=
# endif

SRCS	:= ${wildcard ${SRC_PATH}/*.c}
# OBJS	= ${patsubst srcs/libft/%.c, ${OBJ_PATH}/%.o, ${SRCS}}
# OBJS	= ${patsubst srcs/printf/%.c, ${OBJ_PATH}/%.o, ${SRCS}}
# OBJS	:= ${addprefix ${OBJ_PATH}/, ${addsuffix .o, ${notdir ${basename ${SRCS}}}}}
OBJS	= $(patsubst %.c,$(OBJ_PATH)/%.o,$(notdir $(SRCS)))
# OBJS	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)/%.o,$(SRCS)）

# all:		${OBJS_PATH} ${NAME}
all			:	${NAME}
debug		:	${DEBUG}

${NAME}:	${OBJS}
			${AR} ${ARFLAGS} $@ $^

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c* ./Makefile ./includes/*.h
					mkdir -p ${@D}
					${CC} ${CFLAGS} -I{INCLUDES} ${CFLAGS} -c $< -o $@

clean:		
			${RM} ${OBJ_PATH}

fclean:		clean
			${RM} ${NAME}
			${RM} ${DEBUG}

re:			fclean all

cleanbug:	
			${RM} ${DEBUG}

redebug:	cleanbug debug

${DEBUG}:	${OBJS} main.c
			$(CC) $(CFLAGS) $(CSAN) -I$(INCLUDES) $^ -o $@

.PHONY:		all clean fclean re debug