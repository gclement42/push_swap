SRCS = push_swap.c main.c

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
	make -C libft_utils
	make -C ft_printf
	cp libft_utils/libft.a ./push_swap.a
	${LIB} ${NAME} ${OBJS} push_swap.a

clean:		
	${RM}  ${OBJS} a.out
	make clean -C libft_utils
	make clean -C ft_printf

fclean:	clean 
	${RM} ${NAME} a.out
	make fclean -C libft_utils
	make fclean -C ft_printf

re:	fclean all

.PHONY: all clean fclean re