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

void command_receiver(char *buffer, client_t *log)
{
    char *tab[7] = {"/login", "/logout", "/users", "/user", "/send",
    "/messages" ,NULL};
    void (*build_ptr[7])(char *buffer, client_t *log) =
        {login_receipt, logout_receipt,
        users_receipt, user_receipt, send_receipt, messages_receipt};
    int compare;
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
