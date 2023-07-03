/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin [WSL : Ubuntu]
** File description:
** command_handler
*/

#include "../clients.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../../libs/myteams/logging_client.h"
#include <stdio.h>

void compare_command(char *buffer, client_t *log, char **tab)
{
    void (*build_ptr[7])(char *buffer, client_t *log) = {login_command,
    logout_command, users_command, user_command, send_command,
    messages_command};
    int compare = 0;
    char *buffer_copy = strdup(buffer);

    for (int i = 0; tab[i] != NULL; i++) {
        compare = strncmp(buffer_copy, tab[i], strlen(tab[i]));
        if (compare == 0) {
            (*build_ptr[i])(buffer, log);
            free(buffer_copy);
            return;
        }
    }
    free(buffer_copy);
    return;
}

void command_handler(char *buffer, client_t *log)
{
    char *tab[7] = {"/login", "/logout", "/users", "/user",
    "/send", "/messages", NULL};
    char *buffer_copy = strdup(buffer);
    char *space_pos = strchr(buffer_copy, ' ');

    if (space_pos != NULL)
        *space_pos = '\0';
    compare_command(buffer, log, tab);
    free(buffer_copy);
    return;
}
