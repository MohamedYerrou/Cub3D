NAME 			= cub3D

LIBPATH		= utils/Libft

LIB				= $(LIBPATH)/libft.a

SRCS 			= main.c utils/Get_next_line/get_next_line.c \
				utils/Get_next_line/get_next_line_utils.c \
				medpart/parsing/bring_data.c \
				medpart/parsing/parsing_utils.c \
				medpart/parsing/basic_parse.c \
				medpart/parsing/args_parse.c \
				medpart/parsing/data_parse.c \
				medpart/parsing/create_map.c \
				medpart/parsing/check_borders.c \
				medpart/parsing/check_map.c \
				medpart/init/init_mlx.c \

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I utils/Libft #-fsanitize=address

RM				= rm -f

all:			${NAME}

$(NAME):	$(LIB) $(OBJS)
				$(CC) ${CFLAGS} ${OBJS} ${LIB} -lmlx -lX11 -lXext -lm -o ${NAME}

$(LIB):
			make -C $(LIBPATH)

clean:
				$(RM) $(OBJS)
				make -C $(LIBPATH) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBPATH) fclean

re:				fclean $(NAME)
		make -C $(LIBPATH) re

.PHONY:			all clean fclean re
