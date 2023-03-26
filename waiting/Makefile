NAME = puissance4
SRCS = main.c affichage.c resolution.c creation.c verifications.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -D HAUTEUR=10 -D LARGEUR=10 -D NB_JETONS=4 -o ${NAME} ${SRCS}
			./${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all