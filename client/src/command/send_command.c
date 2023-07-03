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

void send_command(char *buffer, client_t *log)
{
    buffer += 6;
    buffer[strcspn(buffer, "\n")] = '\0';
    dprintf(log->sock, "%s %s", "send", buffer);
}

void send_receipt(char *buffer, client_t *log UNUSED)
{
    char **tab;

    buffer += 6;
    tab = str_to_word_array(buffer, "|\n");
    if (strcmp(tab[0], "-1") == 0) {
        client_error_unknown_user(tab[1]);
        return;
    }
    client_event_private_message_received(tab[0], tab[1]);
}
