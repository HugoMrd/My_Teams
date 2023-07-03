##
## EPITECH PROJECT, 2023
## B-NWP-400-PAR-4-1-myteams-lucas.mechin
## File description:
## Makefile
##

SRC =           src/clients.c 					\
				src/main.c 						\
				src/command.c					\
				src/str_to_word_array.c			\
				src/manage_clients.c			\
				src/command/command_handler.c	\
				src/command/login_command.c		\
				src/command/logout_command.c 	\
				src/command/users_command.c		\
				src/command/send_command.c		\
				src/command/user_command.c		\
				src/command/command_receive.c	\
				src/command/messages_command.c	\

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

NAME    =       myteams_cli

CFLAGS          += -Wall -Wextra -g3

CPPFLAGS        =       -I include/

LDFLAGS	+=	-L../libs/myteams/ -lmyteams -luuid

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:     fclean all

.PHONY: all create clean fclean re NAME
