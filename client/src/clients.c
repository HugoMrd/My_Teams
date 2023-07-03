/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** clients
*/

#include "clients.h"
#include "../../libs/myteams/logging_server.h"
#include "../../libs/myteams/logging_client.h"
#include <stdio.h>

int manage_input(client_t *log)
{
    int data;
    char buffer[MAXSIZE];

    data = read(0, buffer, sizeof(buffer) - 1);
    buffer[data] = '\0';
    command_handler(buffer, log);
    return 0;
}

int sock_error(int sock)
{
    if (sock == -1) {
        fprintf(stderr, "Failed to create socket.\n");
        return (84);
    }
    return (0);
}

int clients(char *ip, int port)
{
    int sock = create_socket(ip, port);
    client_t log;
    fd_set read_fds;
    int max_fd = 0;

    log.is_connect = false;
    log.sock = sock;
    if (sock_error(sock) == 84)
        return (84);
    max_fd = sock > STDIN_FILENO ? sock : STDIN_FILENO;
    while (1) {
        read_fds = select_clients(sock, max_fd, read_fds);
        client_handler(read_fds, &log);
        client_receiver(read_fds, sock, &log);
    }
    close(sock);
    return 0;
}
