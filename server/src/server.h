/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-lucas.mechin
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/select.h>
    #include <uuid/uuid.h>
    #include <time.h>
    #include <sys/queue.h>
    #include <stdbool.h>
    #include <string.h>
    #define MAXSIZE 1024
    #define UNUSED __attribute__((unused))

typedef struct client_s {
    int fd;
    char *username;
    char *uid;
    char line[MAXSIZE];
    bool is_connect;
} client_t;

typedef struct data_s {
    client_t clients[MAXSIZE];
    client_t loaded_clients[MAXSIZE];
    int user_loaded_count;
    int main_socket;
} data_t;

int handle_client(data_t *data, int i);

void command_handler(char *buffer, data_t *data, int i);

void check_buff(char *buffer);

char **my_str_to_word_array(char *str);

void load_clients(data_t *data);

int store_client(int fd, data_t *data);

void is_accept(fd_set readfds, struct sockaddr_in stru, data_t *data);

int loop_client(data_t *data, fd_set readfds);

void loop_server(data_t *data);

int server(int port);

int create_socket(int port);

int accept_connection(int sock, struct sockaddr_in *stru);

void login_command(char *buffer, data_t *data, int i);

void logout_command(char *buffer, data_t *data, int i);

void users_command(char *buffer, data_t *data, int i);

void fill_struct_array(char *buffer, client_t *log);

void user_command(char *buffer, data_t *data, int i);

void send_command(char *buffer, data_t *data, int i);

void add_to_loaded(int i, data_t *data);

char **str_to_word_array(char *str, char *delim);

void replace_char(char* str, char old, char new);

int add_message(client_t from, client_t to, char *msg);

void messages_command(char *buffer, data_t *data, int i);

char **check_buffer(char *buffer, int expected_size);

#endif /* !STRUCT_H_ */
