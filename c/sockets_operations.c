#include "sockets_operations.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

/*
 * Escriba un programa que reciba paquetes de 10 bytes por el puerto TCP 815 
 * y los imprima por pantalla. Al recibir el byte 0xff debe cerrarse 
 * ordenadamente. No considere errores.
 */
void recibirEImprimir815(){
    // create
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // bind and listen
    struct sockaddr_in addr;
    memset((char *) &addr, 0, sizeof(addr));
    int port = 815;
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(server_socket, (struct sockaddr *) &addr, (socklen_t)sizeof(struct sockaddr));
    
    listen(server_socket, 1);
    
    // accept
    int client_socket = accept(server_socket, NULL, NULL);
    
    // receive
    int has_ended = 0;
    char buffer[10];

    while (!has_ended) {
        recv(client_socket,
            &buffer[0],
            10,
            MSG_NOSIGNAL);

        if (buffer[0] == 255){
            has_ended = 1;
        } else {
            printf("%s", buffer);
        }
    }

    // shutdown
    shutdown(client_socket, SHUT_RDWR);
    shutdown(server_socket, SHUT_RDWR);
}