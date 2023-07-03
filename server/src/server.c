/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** server
*/

#include "server.h"

int create_socket(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in stru;

    if (sock < 0)
        return 84;
    stru.sin_family = AF_INET;
    stru.sin_port = htons(port);
    stru.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *) &stru, sizeof(stru)))
        return 84;
    if (listen(sock, SOMAXCONN))
        return 84;
    return sock;
}

void nexxt(int *max, data_t *data, int i)
{
    if (data->clients[i].fd > *max)
        *max = data->clients[i].fd;
}

void loop_server(data_t *data)
{
    struct sockaddr_in stru;
    fd_set readfds;
    fd_set writefds;
    int max;

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(data->main_socket, &readfds);
    max = data->main_socket;
    for (int i = 0; i < MAXSIZE; i++) {
        if (data->clients[i].fd >= 0) {
            FD_SET(data->clients[i].fd, &writefds);
            FD_SET(data->clients[i].fd, &readfds);
            nexxt(&max, data, i);
        }
    }
    select(max + 1, &readfds, &writefds, NULL, NULL);
    is_accept(readfds, stru, data);
    loop_client(data, readfds);
}

int server(int port)
{
    data_t data;
    data.main_socket = create_socket(port);
    data.user_loaded_count = 0;
    load_clients(&data);

    if (data.main_socket == -1)
        return 84;
    while (1)
        loop_server(&data);
    return 0;
}
