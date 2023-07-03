/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** handle_connexion
*/

#include "server.h"

int accept_connection(int sock, struct sockaddr_in *stru)
{
    socklen_t len = sizeof(*stru);
    int fd = accept(sock, (struct sockaddr *) stru, &len);

    return fd;
}

void is_accept(fd_set readfds, struct sockaddr_in stru,
data_t *data)
{
    if (FD_ISSET(data->main_socket, &readfds) != 0) {
        int fd = accept_connection(data->main_socket, &stru);
        store_client(fd, data);
    }
}
