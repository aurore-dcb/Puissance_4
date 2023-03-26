NAME = puissance4

SRCS_C = Classic/*.c
SRCS_T = Transverse/*.c
SRCS_I = Interface/*.c

OBJS_C = ${SRCS_C:.c=.o}
OBJS_T = ${SRCS_T:.c=.o}
OBJS_I = ${SRCS_I:.c=.o}

INCLUDE_C = Includes/puissance_4.h
INCLUDE_T = Includes/transverse_puissance4.h
INCLUDE_I = Includes/interafce_puissance4.h


CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS_I} ${OBJS_T}
			${CC} ${CFLAGS} -I ${INCLUDES_T} -D HAUTEUR=6 -D LARGEUR=7 -D NB_JETONS=4 -o ${NAME} ${SRCS_I} ${SRCS_T}

all:		${NAME}

classic:	${OBJS_C} ${OBJS_T}
			${CC} ${CFLAGS} -I ${INCLUDES} -D HAUTEUR=6 -D LARGEUR=7 -D NB_JETONS=4 -o ${NAME} ${SRCS_C} ${SRCS_T}

interface:	${NAME}

clean:
			${RM} ${OBJS_I} ${OBJS_T} ${OBJS_C}

fclean:		clean
			${RM} ${NAME}

re:			fclean all