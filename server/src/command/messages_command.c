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

int check_if_user_exist(data_t *data, char *uid)
{
    int sec_user = -1;

    for (int a = 0; a < data->user_loaded_count; a++) {
        if (strcmp(data->loaded_clients[a].uid, uid) == 0) {
            sec_user = a;
            break;
        }
    }
    return sec_user;
}

int check_line(char **tab, data_t *data, int sec_user, int i)
{
    if ((strcmp(tab[0], data->clients[i].username) == 0 && strcmp(tab[1],
        data->loaded_clients[sec_user].username) == 0)) {
            return 1;
    } else if ((strcmp(tab[0], data->loaded_clients[sec_user].username) == 0 && strcmp(tab[1],
        data->clients[i].username) == 0)) {
            return 1;
    }
    return 0;
}

int search_convo(data_t *data, int i, char *uid)
{
    char **tab = malloc(sizeof(char *) * 2);
    int sec_user = check_if_user_exist(data, uid);
    char *copy = strdup(data->clients[i].line);

    tab[0] = strtok(copy, ";");
    tab[1] = strtok(NULL, ";");
    if (sec_user == -1)
        return; // ICI SI ON NE TROUVE PAS L'
    if (check_line(tab, data, sec_user, i) == 1)
        dprintf(data->clients[i].fd, "/messages %s\n", data->clients[i].line);
    free(copy);
    return 0;
}

void messages_command(char *buffer, data_t *data, int i)
{
    char **tab;
    FILE *fp = fopen("messages.txt", "r+");

    buffer += 9;
    tab = check_buffer(buffer, 1);
    if (tab == NULL) {
        return;
    }
    while (fgets(data->clients[i].line, 1024, fp) != NULL) {
        search_convo(data, i, tab[0]);
    }

    fclose(fp);
    return;
}
