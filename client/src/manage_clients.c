/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin [WSL: kali-linux]
** File description:
** manage_clients
*/

#include "clients.h"
#include "../../libs/myteams/logging_server.h"
#include "../../libs/myteams/logging_client.h"
#include <stdio.h>

fd_set select_clients(int sock, int max_fd, fd_set read_fds)
{
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    FD_SET(sock, &read_fds);

    if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
        perror("select");
        exit(84);
    }
    return (read_fds);
}

void client_handler(fd_set read_fds, client_t *log)
{
    char input_buffer[MAXSIZE];

    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
        fgets(input_buffer, sizeof(input_buffer), stdin);
        command_handler(input_buffer, log);
    }
}

int client_data(int data)
{
    if (data == -1) {
        exit(84);
    } else if (data == 0) {
        fprintf(stderr, "Server closed the connection.\n");
        exit(84);
    }
    return (data);
}

void client_receiver(fd_set read_fds, int sock, client_t *log)
{
    int data = 0;

    if (FD_ISSET(sock, &read_fds)) {
        data = read(sock, log->buffer, sizeof(log->buffer) - 1);
        log->buffer[data + 1] = '\0';
        data = client_data(data);
        command_receiver(log->buffer, log);
    }
}
