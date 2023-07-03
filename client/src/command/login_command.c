/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin [WSL : Ubuntu]
** File description:
** login_command
*/

#include "../clients.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../../libs/myteams/logging_client.h"
#include <stdio.h>

void login_command(char *buffer, client_t *log)
{
    buffer += 7;
    buffer[strcspn(buffer, "\n")] = '\0';
    dprintf(log->sock, "%s %s", "log_user", buffer);
}

void login_receipt(char *buffer, client_t *log UNUSED)
{
    char *token = NULL;
    char **tab = malloc(sizeof(char *) * 2);

    token = strtok(buffer, " \n");;
    for (int i = 0; i < 3; i++) {
        tab[i] = strdup(token);
        token = strtok(NULL, " \n");
    }
    client_event_logged_in(tab[1], tab[2]);
}
