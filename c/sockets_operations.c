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

/*
 * Defina una rutina en C que se conecte a la IP 8.8.8.8, al puerto 8192 y 
 * reciba un archivo binario. El archivo recibido debe ser descargado a un 
 * archivo llamado recibido.bin cuidando el uso de recursos de memoria. El 
 * archivo finaliza al detectar conexion cerrada.
 */
void recibirBinario(){
    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // conect
    struct sockaddr_in their_addr;
    
    their_addr.sin_family = AF_INET; // orden de bytes de la máquina
    their_addr.sin_port = htons(8192); // short, orden de bytes de la red
    their_addr.sin_addr.s_addr = inet_addr("8.8.8.8");
    memset(&(their_addr.sin_zero), 8, sizeof (int)); // poner a 0 el resto

    int conn_status = connect(client_socket, (struct sockaddr *) &their_addr, sizeof (struct sockaddr));

    if (conn_status == -1) {
        puts("conection error");
        return;
    } else {
        // receive
        char chunk[50] = {0};

        FILE *fpRecibido = fopen("recibido.bin", "w");
        if (fpRecibido != NULL){
            while (recv(client_socket, &chunk[0], 50, MSG_NOSIGNAL) > 0){
                fputs(chunk, fpRecibido);
            }

            fclose(fpRecibido);
        } else {
            puts("file error.");
        }
    }
    
    // shutdown
    shutdown(client_socket, SHUT_RD);
}