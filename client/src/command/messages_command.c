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

void print_one_message()
{
    // client_private_message_print_messages()
}

void print_messages(char **tab)
{
    char **new_tab;
    char *first_uid = tab[2];
    char *second_uid = tab[3];

    printf("%s %s\n", first_uid, second_uid);
    for (int i = 4; tab[i] != NULL; i++)
    {
        new_tab = str_to_word_array(tab[i], "-");
    }
}

void messages_command(char *buffer, client_t *log)
{
    buffer += 10;
    dprintf(log->sock, "messages %s", buffer);
}

void messages_receipt(char *buffer, client_t *log UNUSED)
{
    char *copy;
    char **tab;

    buffer += 10;
    copy = strdup(buffer);
    tab = str_to_word_array(buffer,";\n");
    print_messages(tab);
    free(copy);
}
