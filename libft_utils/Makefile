SRCS = ft_atoi.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstadd_front.c 

OBJS = ${SRCS:.c=.o}

HEAD = libft.h

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

LIB = ar rc

RM = rm -f

%.o: %.c  ${HEAD} Makefile
	CC ${FLAGS} -I${HEAD} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
	${LIB} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re