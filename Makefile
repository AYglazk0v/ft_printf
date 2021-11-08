NAME 		=	libftprintf.a
SRC_NAME	=	./src/ft_puts.c \
				./src/ft_solve_char.c \
				./src/ft_solve_di.c \
				./src/ft_solve_percent.c \
				./src/ft_solve_point.c \
				./src/ft_solve_str.c \
				./src/ft_solve_u.c \
				./src/ft_solve_xx.c \
				./src/printf.c \
				./src/support_func.c \
				./src/support_func_continue.c

SRC_BONUS	=	${SRC_NAME}

OBJ_NAME	=	${SRC_NAME:.c=.o}
OBJ_BONUS	=	${SRC_BONUS:.c=.o}
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc
RM			= 	rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ_NAME}
				ar rcs ${NAME} ${OBJ_NAME}

bonus:	${OBJ_NAME} ${OBJ_BONUS}	
				ar rcs ${NAME} ${OBJ_NAME} ${OBJ_BONUS}

.PHONY: 		all clean fclean re bonus

all:	${NAME}

clean:
				${RM} ${OBJ_NAME} ${OBJ_BONUS}

fclean:	clean	
				${RM} ${NAME}

re: fclean all
