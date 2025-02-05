NAME = Cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBRARY = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = cub3d.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJ)
		${CC} ${CFLAGS} ${OBJ} ${LIBRARY} -o ${NAME}

clean :
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re