/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** command
*/

#include "clients.h"
#include "../../libs/myteams/logging_server.h"
#include "../../libs/myteams/logging_client.h"
#include <stdio.h>

int create_socket(char *ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in stru;

    if (sock < 0)
        return 84;
    stru.sin_family = AF_INET;
    stru.sin_port = htons(port);
    stru.sin_addr.s_addr = inet_addr(ip);
    if (connect(sock, (struct sockaddr *) &stru, sizeof(stru)) == -1)
        return 84;
    return sock;
}
