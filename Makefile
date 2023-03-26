NAME = puissance4

SRCS_C = Classic/classic_affichage.c Classic/classic_main.c Classic/classic_resolution.c
SRCS_T = Transverse/creation.c Transverse/verifications.c
SRCS_I = Interface/interface_main.c Interface/interface_resolution.c Interface/interface_grille.c

OBJS_C = ${SRCS_C:.c=.o}
OBJS_T = ${SRCS_T:.c=.o}
OBJS_I = ${SRCS_I:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lSDL2 -lSDL2_image -lSDL_gfx

RM = rm -f

${NAME}:	${OBJS_I} ${OBJS_T}
			${CC} ${CFLAGS} -D HAUTEUR=8 -D LARGEUR=10 -D NB_JETONS=4 -o ${NAME} ${SRCS_I} ${SRCS_T} ${LFLAGS}

all:		${NAME}

classic:	${OBJS_C} ${OBJS_T}
			${CC} ${CFLAGS} -D HAUTEUR=6 -D LARGEUR=7 -D NB_JETONS=4 -o ${NAME} ${SRCS_C} ${SRCS_T}

interface:	${NAME}

clean:
			${RM} ${OBJS_I} ${OBJS_T} ${OBJS_C}

fclean:		clean
			${RM} ${NAME}

re:			fclean all