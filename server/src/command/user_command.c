/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin [WSL : Ubuntu]
** File description:
** login_command
*/

#include "../server.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../../libs/myteams/logging_client.h"
#include <stdio.h>

void user_run(char *buffer, data_t *data, int i, int a)
{
    if (data->loaded_clients[a].is_connect == true &&
    strcmp(data->loaded_clients[a].uid, buffer) == 0) {
        dprintf(data->clients[i].fd, "/user %s %s 1\n",
        data->loaded_clients[a].username, data->loaded_clients[a].uid);
    } else if (data->loaded_clients[a].is_connect == false &&
        strcmp(data->loaded_clients[a].uid, buffer) == 0){
        dprintf(data->clients[i].fd, "/user %s %s 0\n",
        data->loaded_clients[a].username, data->loaded_clients[a].uid);
    }
}

void user_command(char *buffer, data_t *data, int i)
{
    char **tab;

    buffer += 5;
    tab = check_buffer(buffer, 1);
    if (tab == NULL) {
        return;
    }
    for (int a = 0; a < data->user_loaded_count; a++)
        user_run(tab[0], data, i, a);
}
