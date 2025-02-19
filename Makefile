NAME 			= cub3D

LIBPATH		= parsing_med/utils/Libft

LIB				= $(LIBPATH)/libft.a

SRCS 			= main.c \
				parsing_med/utils/Get_next_line/get_next_line_utils.c \
				parsing_med/utils/Get_next_line/get_next_line.c \
				parsing_med/parsing/fill_color_texture.c \
				parsing_med/parsing/parsing_utils.c \
				parsing_med/parsing/check_borders.c \
				parsing_med/parsing/check_texture.c \
				parsing_med/parsing/basic_parse.c \
				parsing_med/parsing/bring_data.c \
				parsing_med/parsing/args_parse.c \
				parsing_med/parsing/data_parse.c \
				parsing_med/parsing/create_map.c \
				parsing_med/parsing/check_map.c \
				parsing_med/exit.c \
				raycasting_bilal/raycasting.c \
				raycasting_bilal/dda_line.c \
				raycasting_bilal/render.c \
				raycasting_bilal/hook.c

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
