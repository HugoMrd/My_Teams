/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin [WSLÂ : Ubuntu]
** File description:
** login_command
*/

#include "../server.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../../libs/myteams/logging_client.h"
#include <stdio.h>

void load_client(data_t *data, int i)
{
    for (int a = 0; data->loaded_clients[a].username != NULL; a++) {
        if (strcmp(data->loaded_clients[a].username,
            data->clients[i].username) == 0) {
                data->clients[i].uid = data->loaded_clients[a].uid;
                data->loaded_clients[a].is_connect = true;
                data->loaded_clients[a].fd = data->clients[i].fd;
        }
    }
}

int add_username(char *username, data_t *data, int i)
{
    FILE* fp;
    uuid_t user;
    char user_uid[37];

    fp = fopen("usernames.txt", "a+");
    if (fp == NULL)
        return -1;
    uuid_generate_random(user);
    uuid_unparse(user, user_uid);
    fprintf(fp, "%s;%s\n", username, user_uid);
    fclose(fp);
    data->clients[i].uid = strdup(user_uid);
    data->clients[i].username = strdup(username);
    return 0;
}

int check_username(char *username)
{
    FILE* fp;
    char buffer[50];
    char *token;

    fp = fopen("usernames.txt", "a+");
    if (fp == NULL)
        return -1;
    while (fgets(buffer, 50, fp) != NULL) {
        token = strtok(buffer, ";");
        if (token != NULL && strcmp(token, username) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void login_command(char *buffer, data_t *data, int i)
{
    char **tab;

    buffer += 9;
    tab = check_buffer(buffer, 1);
    if (tab == NULL)
        return;
    if (check_username(tab[0]) == 0) {
        add_username(tab[0], data, i);
        add_to_loaded(i, data);
        server_event_user_created(data->clients[i].uid, tab[0]);
        server_event_user_logged_in(data->clients[i].uid);
    } else {
        data->clients[i].username = strdup(tab[0]);
        load_client(data, i);
        server_event_user_logged_in(data->clients[i].uid);
    }
    dprintf(data->clients[i].fd, "/login %s %s\n", data->clients[i].uid,
    data->clients[i].username);
    data->clients[i].is_connect = true;
}

void fill_struct_array(char *buffer, client_t *client)
{
    char **tab = malloc(sizeof(char *) * 5);
    char *token = strtok(buffer, ";\n");
    int i = 0;

    while (token != NULL && i < 5) {
        tab[i] = strdup(token);
        token = strtok(NULL, ";\n");
        i++;
    }
    client->username = strdup(tab[0]);
    client->uid = strdup(tab[1]);
    client->is_connect = false;
    server_event_user_loaded(client->uid, client->username);
}
