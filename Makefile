NAME = puissance4

SRCS_C = Classic/classic_affichage.c Classic/classic_main.c Classic/classic_resolution.c Classic/classic_verifications.c
SRCS_T = Transverse/creation.c
SRCS_I = Interface/interface_main.c Interface/interface_resolution.c Interface/interface_grille.c Interface/interface_animations.c Interface/interface_confetti.c Interface/interface_verifications.c

OBJS_C = ${SRCS_C:.c=.o}
OBJS_T = ${SRCS_T:.c=.o}
OBJS_I = ${SRCS_I:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lSDL2 -lSDL2_image -lSDL_gfx

RM = rm -f

HAUTEUR = -D HAUTEUR=6 
LARGEUR = -D LARGEUR=7
JETONS = -D NB_JETONS=3

${NAME}:	${OBJS_I} ${OBJS_T}
			${CC} ${CFLAGS} ${HAUTEUR} ${LARGEUR} ${JETONS} -o ${NAME} ${SRCS_I} ${SRCS_T} ${LFLAGS}

all:		${NAME}

classic:	${OBJS_C} ${OBJS_T}
			${CC} ${CFLAGS} ${HAUTEUR} ${LARGEUR} ${JETONS} -o ${NAME} ${SRCS_C} ${SRCS_T}

interface:	${NAME}

clean:
			${RM} ${OBJS_I} ${OBJS_T} ${OBJS_C}

fclean:		clean
			${RM} ${NAME}

re:			fclean all