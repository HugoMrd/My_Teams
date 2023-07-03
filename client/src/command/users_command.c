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

int status_connection(char *str)
{
    if (strncmp(str, "1", 1) == 0)
        return 1;
    return 0;
}

void users_command(char *buffer UNUSED, client_t *log)
{
    dprintf(log->sock, "users\n");
}

void users_receipt(char *buffer, client_t *log UNUSED)
{
    char **tab = str_to_word_array(buffer, "|");
    char **user_tab;

    for (int i = 2; i < atoi(tab[1]) + 2; i++) {
        user_tab = str_to_word_array(tab[i], " ");
        client_print_users(user_tab[0], user_tab[1], atoi(user_tab[2]));
    }
}
