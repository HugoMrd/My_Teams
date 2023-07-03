/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** main
*/

#include "server.h"
#include "ctype.h"

int has_letters(const char *str)
{
    while (*str) {
        if (isalpha(*str))
            return (1);
        str++;
    }
    return (0);
}

void help(void)
{
    char *s = "      ";

    printf("%s\n", "USAGE: ./myteams_server port\n");
    printf("%s%s", s, "port  is the port number on which the server");
    printf("%s\n", " socket listens.");
}

int main (int ac, char **av)
{
    if (strcmp(av[1], "-help") == 0) {
        help();
        return (0);
    }
    if ((ac > 2 || ac < 2) || (has_letters(av[1]) == 1))
        return (84);
    else {
        if (server(atoi(av[1])) == 84)
            return (84);
    }
    return (0);
}
