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

void user_command(char *buffer, client_t *log)
{
    buffer += 6;
    buffer[strcspn(buffer, "\n")] = '\0';
    dprintf(log->sock, "%s %s", "user", buffer);
}

void user_receipt(char *buffer, client_t *log UNUSED)
{
    char *token;
    char **tab = malloc(sizeof(char *) * 3);

    token = strtok(buffer, " \n");;
    for (int i = 0; token != NULL; i++) {
        tab[i] = strdup(token);
        token = strtok(NULL, " \n");
    }
    client_print_user(tab[2], tab[1], atoi(tab[3]));
}
