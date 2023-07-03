/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** str_to_word_array
*/



#include "clients.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char **str_to_word_array(char *str, char *delim)
{
    char **wordtab = NULL;
    char *token = strtok(str, delim);
    int i = 0;

    while (token != NULL) {
        wordtab = realloc(wordtab, sizeof(char*) * (i + 1));
        wordtab[i] = strdup(token);
        i++;
        token = strtok(NULL, delim);
    }
    wordtab = realloc(wordtab, sizeof(char*) * (i + 1));
    wordtab[i] = NULL;
    return wordtab;
}

void free_doublearr(char **doublearr)
{
    int i = 0;

    while (doublearr[i] != NULL)
        free(doublearr[i]);
    free(doublearr);
}
