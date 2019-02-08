#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

void pruebas_armado_conexion(){
    /* 
     * Los pasos para establecer un socket del lado del cliente son:
     * 1. Crear un socket con la función socket()
     * 2. Enlazar el socket a la dirección del servidor utilizando connect()
     * 3. Enviar y recibir datos con send() y recv()
     * 4. Cerrar todos los sockets debidamente con close() al finalizar.
     */
    
    // 1
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    
    // 2
    // struct hostent *he; si quiero hacer el gethostbyname
    struct sockaddr_in server_addr;
    
    memset((char*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = inet_addr("9.8.7.6");    
    
    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
    
    // 3
    char buf[250];
    send(client_socket, (void*)&buf[0], 250, MSG_NOSIGNAL);
    recv(client_socket, (void*)&buf[0], 250, MSG_NOSIGNAL);
    
    // 4
    shutdown(client_socket, SHUT_RDWR);
    
    /*
     * Los pasos para establecer un socket del lado del servidor son:
     * 1. Crear un socket con la función socket()
     * 2. Enlazar el socket a una dirección utilizando la función bind().
     * Para un socket en internet, la dirección consiste en un numero de puerto
     * en la maquina donde es ejecutado.
     * 3. Escuchar por conexiones con la función listen()
     * 4. Aceptar conexiones con la función accept()
     * 5. Enviar y recibir datos con send() y recv()
     * 6. Finalizar la transmisión en el socket que escucha conexiones con
     * shutdown()
     * 7. Cerrar todos los sockets debidamente con close() al finalizar.
     */
    // 1
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // 2
    struct sockaddr_in addr;
        
    memset((char*)&addr, 0, sizeof(struct sockaddr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("9.8.7.6");
    addr.sin_port = htons(7777);
    
    //int bind_res = bind(server_socket, (struct sockaddr *)&addr, (socklen_t)sizeof(struct sockaddr));
        
    // 3
    //int listen_res = listen(server_socket, 1);
    
    // 4
    int connected_socket = accept(server_socket, NULL, NULL);
    
    // 5
    send(connected_socket, (void*)&buf[0], 250, MSG_NOSIGNAL);
    recv(connected_socket, (void*)&buf[0], 250, MSG_NOSIGNAL);
    
    // 6
    shutdown(connected_socket, SHUT_RDWR);
    shutdown(server_socket, SHUT_RDWR);
}