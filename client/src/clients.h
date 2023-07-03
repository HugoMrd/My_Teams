/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** clients
*/

#ifndef CLIENTS_H_
    #define CLIENTS_H_
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/select.h>
    #include <time.h>
    #include <stdbool.h>
    #include <uuid/uuid.h>
    #define MAXSIZE 1024
    #define UNUSED __attribute__((unused))

typedef struct client_s {
    bool is_connect;
    char *uuid;
    char *username;
    int index;
    int sock;
    char buffer[MAXSIZE];
} client_t;

int clients(char *ip, int port);

int create_socket(char *ip, int port);

int check_username(char *username);

int add_username(char *username, client_t *log);

void fill_struct(char *user, client_t *log);

char **str_to_word_array(char *str, char *delim);

//COMMAND//
void command_handler(char *buffer, client_t *log);
void login_command(char *buffer, client_t *log);
void logout_command(char *buffer, client_t *log);
void users_command(char *buffer UNUSED, client_t *log);
void user_command(char *buffer, client_t *log);
void send_command(char *buffer, client_t *log);
void messages_command(char *buffer UNUSED, client_t *log);

//COMMAND RECEIVE//
void command_receiver(char *buffer, client_t *log);
void login_receipt(char *buffer, client_t *log);
void logout_receipt(char *buffer, client_t *log);
void user_receipt(char *buffer, client_t *log);
void users_receipt(char *buffer, client_t *log);
void send_receipt(char *buffer, client_t *log);
void messages_receipt(char *buffer, client_t *log UNUSED);

//MANAGE CLIENTS//
fd_set select_clients(int sock, int max_fd, fd_set read_fds);
void client_handler(fd_set read_fds, client_t *log);
void client_receiver(fd_set read_fds, int sock, client_t *log);

#endif /* !CLIENTS_H_ */
