NAME = puissance4
SRCS = main.c affichage.c resolution.c creation.c verifications.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -D HAUTEUR=6 -D LARGEUR=7 -o ${NAME} ${SRCS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all