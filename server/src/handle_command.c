/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** handle_command
*/

#include "../../libs/myteams/logging_server.h"
#include "server.h"

void compare_command(char *buffer, data_t *data, int a, char **tab)
{
    void (*build_ptr[6])(char *buffer, data_t *data, int a) =
    {login_command, users_command, logout_command, user_command
    , send_command, messages_command};
    int compare = 0;
    char *buffer_copy = strdup(buffer);

    for (int i = 0; tab[i] != NULL; i++) {
        compare = strncmp(buffer_copy, tab[i], strlen(tab[i]));
        if (compare == 0) {
            (*build_ptr[i])(buffer, data, a);
            free(buffer_copy);
            return;
        }
    }
    free(buffer_copy);
    return;
}

void command_handler(char *buffer, data_t *data, int a)
{
    char *tab[7] = {"log_user","users", "logout_user","user",
    "send", "messages", NULL};
    char *buffer_copy = strdup(buffer);
    char *space_pos = strchr(buffer_copy, ' ');

    if (space_pos != NULL)
        *space_pos = '\0';
    compare_command(buffer, data, a, tab);
    free(buffer_copy);
    return;
}
