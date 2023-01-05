SRCS = ft_atoi.c check_error.c state_stack.c directives_all.c push_swap.c directive.c manage_stack.c main.c

OBJS = ${SRCS:.c=.o}

HEAD = push_swap.h

FLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

LIB = ar rc

RM = rm -f

%.o: %.c  ${HEAD} Makefile
	CC ${FLAGS} -I${HEAD} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} Makefile
	make -C libft
	cp libft/libft.a ./push_swap.a
	${LIB} ${NAME} ${OBJS} push_swap.a

clean:		
	${RM}  ${OBJS} a.out
	make clean -C libft

fclean:	clean 
	${RM} ${NAME} a.out
	make fclean -C libft

re:	fclean all

.PHONY: all clean fclean re