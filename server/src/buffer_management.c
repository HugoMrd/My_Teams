/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** buffer_mangement
*/

#include "server.h"
#include "../../libs/myteams/logging_server.h"

int has_double_quote(const char* str)
{
    int len = strlen(str);

    if (len < 2)
        return 0;
    if (str[0] != '"' || str[len - 1] != '"')
        return 0;
    return 1;
}

void delete_double_coat(char *str)
{
    int len = strlen(str);

    if (len <= 2)
        return;
    for (int i = 0; i < len - 1; i++)
        str[i] = str[i + 1];
    str[len - 2] = '\0';
    return;
}

char **check_buffer(char *buffer, int expected_size)
{
    char **tab;
    int count = 0;
    int has_coat = 0;

    replace_char(buffer, ' ', '|');
    tab = str_to_word_array(buffer, "|\n");

    for (int i = 0; tab[i] != NULL; i++) {
        count++;
        has_coat = has_double_quote(tab[i]);
        if (has_coat == 0)
            break;
        delete_double_coat(tab[i]);
    }
    if (count != expected_size || has_coat == 0) {
        tab = NULL;
    }
    return tab;
}
