SRCS = ft_put_and_count.c ft_printf.c ft_putnbr_base_and_count.c

OBJS = ${SRCS:.c=.o}

HEAD = ft_printf.h

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = ar rc

RM = rm -f

%.o: %.c  ${HEAD} Makefile
	CC ${FLAGS} -I${HEAD} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} Makefile
	make -C Libft
	cp Libft/libft.a ./libftprintf.a
	${LIB} ${NAME} ${OBJS} libftprintf.a

clean:		
	${RM}  ${OBJS} a.out
	make clean -C Libft

fclean:	clean 
	${RM} ${NAME} a.out
	make fclean -C Libft

re:	fclean all

.PHONY: all clean fclean re