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

void send_message(char **tab, data_t *data, int i)
{
    for (int a = 0; a < data->user_loaded_count; a++) {
        if (data->loaded_clients[a].is_connect == true &&
        strcmp(data->loaded_clients[a].uid, tab[0]) == 0) {
            dprintf(data->loaded_clients[a].fd, "/send %s|%s\n",
            data->loaded_clients[a].uid, tab[1]);
            add_message(data->clients[i] ,data->loaded_clients[a]
            ,tab[1]);
            return;
        }
    }
    dprintf(data->clients[i].fd, "/send -1|%s\n", tab[0]);
}

void send_command(char *buffer, data_t *data, int i)
{
    char **tab;

    buffer += 5;
    tab = check_buffer(buffer, 2);
    if (tab == NULL) {
        return;
    }
    send_message(tab, data, i);
}
