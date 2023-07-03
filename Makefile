##
## EPITECH PROJECT, 2023
## B-NWP-400-PAR-4-1-myteams-lucas.mechin
## File description:
## Makefile
##

SERVER =	server/
CLIENT = 	client/

all: server client

server:
		make -C $(SERVER)
		mv ./server/myteams_server .

client:
		make -C $(CLIENT)
		mv ./client/myteams_cli .

clean:
	make clean -C $(SERVER)
	make clean -C $(CLIENT)

fclean:
	make fclean -C $(SERVER)
	make fclean -C $(CLIENT)
	rm -f myteams_cli myteams_server

re: fclean all

.PHONY: all server client clean fclean re
