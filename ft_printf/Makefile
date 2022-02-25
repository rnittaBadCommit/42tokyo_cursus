SRCS    = ft_printf.c ft_printf_integ.c ft_printf_float.c ft_printf_float2.c

SRCS_BONUS = ft_printf.c ft_printf_integ.c ft_printf_float.c ft_printf_float2.c

OBJS    = ${SRCS:.c=.o}
OBJS_BONUS    = ${SRCS_BONUS:.c=.o}
INCS    = includes
NAME    = libftprintf.a
NAME_BONUS = libftprintf.a
LIBC    = ar rc
LIBR    = ranlib
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror 
.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}
all: ${NAME}
bonus: ${OBJS} ${OBJS_BONUS}
	${LIBC} ${NAME} ${OBJS} ${OBJS_BONUS}
	${LIBR} ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_BONUS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all bonus clean fclean re .c.o

