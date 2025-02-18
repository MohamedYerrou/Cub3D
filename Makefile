NAME 			= cub3D

LIBPATH		= medpart/utils/Libft

LIB				= $(LIBPATH)/libft.a

SRCS 			= main.c \
				medpart/utils/Get_next_line/get_next_line_utils.c \
				medpart/utils/Get_next_line/get_next_line.c \
				medpart/parsing/fill_color_texture.c \
				medpart/parsing/parsing_utils.c \
				medpart/parsing/check_borders.c \
				medpart/parsing/check_texture.c \
				medpart/parsing/basic_parse.c \
				medpart/parsing/bring_data.c \
				medpart/parsing/args_parse.c \
				medpart/parsing/data_parse.c \
				medpart/parsing/create_map.c \
				medpart/parsing/check_map.c \
				medpart/exit.c \
				bilpart/raycasting.c \
				bilpart/dda_line.c \
				bilpart/render.c \
				bilpart/hook.c

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Ofast -ffast-math -I utils/Libft -g3 #-fsanitize=address

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

re:				fclean $(NAME)
				make -C $(LIBPATH)

.PHONY:			all clean fclean re
