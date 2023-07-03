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

char *gettime(void)
{
    time_t current_time;
    char* str;

    current_time = time(NULL);
    str = ctime(&current_time);
    return str;
}

void if_found(int end_of_line, int pos, char *msg, FILE *fp)
{
    fseek(fp, end_of_line - 1, SEEK_SET);
    fprintf(fp, ";%i-%s-%s", pos, msg, gettime());
    return;
}

int is_found(client_t *to, client_t *from, char *msg, FILE *fp)
{
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = strtok(from->line, ";");
    tab[1] = strtok(NULL, ";");
    if ((strcmp(tab[0], from->username) == 0 && strcmp(tab[1],
        to->username) == 0)) {
            if_found(ftell(fp), 1, msg, fp);
            return 1;
    } else if ((strcmp(tab[0], to->username) == 0 && strcmp(tab[1],
        from->username) == 0)) {
            if_found(ftell(fp), 2, msg, fp);
            return 1;
    }
    return 0;
}

FILE *search_message(FILE *fp, client_t from, client_t to, char *msg)
{
    int wrote = 0;

    while (fgets(from.line, 1024, fp) != NULL)
        wrote = is_found(&to, &from, msg, fp);
    if (wrote != 1)
        fprintf(fp, "%s;%s;%s;%s;1-%s-%s", from.username, to.username, 
        from.uid, to.uid, msg, gettime());
    return (fp);
}

int add_message(client_t from, client_t to, char *msg)
{
    FILE *fp = fopen("messages.txt", "r+");

    search_message(fp, from, to, msg);
    fclose(fp);
    return 0;
}
