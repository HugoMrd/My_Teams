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

void logout_command(UNUSED char *buffer, data_t *data, int i)
{
    for (int a = 0; data->loaded_clients[a].username != NULL; a++) {
        if (data->clients[i].fd == data->loaded_clients[a].fd) {
            dprintf(data->clients[i].fd, "/logout %s %s\n",
                data->loaded_clients[a].uid,
            data->loaded_clients[a].username);
            data->loaded_clients[a].is_connect = false;
            data->loaded_clients[a].fd = -1;
            server_event_user_logged_out(data->loaded_clients[a].uid);
        }
    }
}
