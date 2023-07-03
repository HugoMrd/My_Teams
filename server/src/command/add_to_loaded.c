/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** add_to_loaded
*/

#include "../server.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../../libs/myteams/logging_client.h"
#include <stdio.h>

void add_to_loaded(int i, data_t *data)
{
    int index = data->user_loaded_count;

    data->user_loaded_count += 1;
    data->loaded_clients[index].username = strdup(data->clients[i].username);
    data->loaded_clients[index].fd = data->clients[i].fd;
    data->loaded_clients[index].uid = strdup(data->clients[i].uid);
    data->loaded_clients[index].is_connect = 1;
    return;
}
