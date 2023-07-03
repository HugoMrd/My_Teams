/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** main
*/

#include "clients.h"
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

    printf("%s\n", "USAGE: ./myteams ip port");
    printf("%s%s", s, "ip   is the server ip adress on which the server");
    printf("%s\n%s%s", " socket listens", s, "port  is the port number on");
    printf("%s\n", " which the server socket listens");
}

int main (int ac, char **av)
{
    if (strcmp(av[1], "-help") == 0) {
        help();
        return (0);
    }
    if (ac > 3 || ac < 3 || (has_letters(av[2]) == 1))
        return (84);
    else {
        if (clients(av[1], atoi(av[2])) == 84)
            return (84);
    }
    return (0);
}
