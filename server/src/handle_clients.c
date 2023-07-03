/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** handle_clients
*/

#include "server.h"
#include "../../libs/myteams/logging_server.h"

int handle_client(data_t *data, int i)
{
    int lenght;
    char buffer[MAXSIZE];

    lenght = read(data->clients[i].fd, buffer, sizeof(buffer) - 1);
    buffer[lenght] = '\0';
    command_handler(buffer, data, i);
    return 0;
}

void load_clients(data_t *data)
{
    FILE *fp;
    char buffer[100];
    int a = 0;

    for (int i = 0; i < MAXSIZE; i++) {
        data->clients[i].fd = -1;
        data->loaded_clients[i].fd = -1;
        data->clients[i].username = strdup("\n");
        data->loaded_clients[i].username = NULL;
    }
    fp = fopen("usernames.txt", "ra");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (fgets(buffer, sizeof(buffer), fp) != NULL && a < MAXSIZE) {
        buffer[strcspn(buffer, "\n")] = '\0';
        fill_struct_array(buffer, &data->loaded_clients[a]);
        data->user_loaded_count += 1;
        a++;
    }
    fclose(fp);
}

int store_client(int fd, data_t *data)
{
    for (int i = 0; i < MAXSIZE; i++) {
        if (data->clients[i].fd < 0) {
            data->clients[i].fd = fd;
            return 1;
        }
    }
    return 0;
}

int suite(data_t *data, int i)
{
    if (handle_client(data, i) == 84)
        return 84;
    return 0;
}

int loop_client(data_t *data, fd_set readfds)
{
    for (int i = 0; i < MAXSIZE; i++) {
        if (data->clients[i].fd >= 0 && FD_ISSET(data->clients[i].fd,
        &readfds) != 0) {
            suite(data, i);
        }
    }
    return (0);
}
