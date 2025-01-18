NAME 			= cub3D

SRCS 			= main.c medpart/parsing/basic_parse.c medpart/parsing/args_parse.c medpart/init/init_data.c \
				utils/Libft/ft_putstr_fd.c utils/Libft/ft_strlen.c
OBJS			= ${SRCS:.c=.o}

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -I.

RM				= rm -f

all:			${NAME}

$(NAME):	$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
