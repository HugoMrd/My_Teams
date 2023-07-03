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

void cat_users(char tmp[MAXSIZE], data_t *data, int a)
{
    strcat(tmp, data->loaded_clients[a].username);
    strcat(tmp, " ");
    strcat(tmp, data->loaded_clients[a].uid);
    strcat(tmp, " ");
    if (data->loaded_clients[a].is_connect == true)
        strcat(tmp, "1");
    else
        strcat(tmp, "0");
    strcat(tmp, "|");
}

void users_command(char *buffer UNUSED, data_t *data, int i)
{
    char str[20];
    char tmp[MAXSIZE] = "";

    sprintf(str, "%d", data->user_loaded_count);
    str[strlen(str)] = '\0';
    strcat(tmp, "/users|");
    strcat(tmp, str);
    strcat(tmp, "|");
    for (int a = 0; a < data->user_loaded_count; a++)
        cat_users(tmp, data, a);
    strcat(tmp, "\r");
    dprintf(data->clients[i].fd, "%s", tmp);
}
