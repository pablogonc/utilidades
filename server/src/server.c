//para recargarlos cambios de las librearias click derecho index update modified files
/*
 * main.c
 *
 *  Created on: 5 ago. 2021
 *      Author: utnso
 */

#include <utils/connection/connection.h>
#include <utils/globals.h>
#include <stdio.h>
#include <semaphore.h>
#include <readline/readline.h>
#include <stdlib.h>

#include <readline/readline.h>
sem_t* sockets_sem;

void suma(int socket){
	int a = connection_recive_int(socket);

	int b = connection_recive_int(socket);

	printf("La suma es : %d\n",(a+b));
}

void resta(int socket){
	int a = connection_recive_int(socket);

	int b = connection_recive_int(socket);

	printf("La resta es : %d\n",(a-b));
}

void mensaje(int socket){
	char* a = connection_recive_string(socket);

	printf("mensaje: %s\n",a);
}

void listenner(void* arg){
	int clientSock = *(int*)arg;
	sem_post(sockets_sem); //libera la espera del server para estar seguro de que no se sobreescriba la variable arg

	printf(PRINT_COLOR_GREEN"cliente conectado: %d \n"PRINT_COLOR_RESET,clientSock);

	int operacion=0;
	int connectionStatus;

	connectionStatus = connection_recive_check(clientSock);

	while(connectionStatus != -1){

		operacion = connection_recive_int(clientSock);

		switch(operacion){
			case OP_SUMA:
				suma(clientSock);
				break;
			case OP_RESTA:
				resta(clientSock);
				break;
			case OP_MENSAJE:
				mensaje(clientSock);
				break;
		}

		connectionStatus = connection_recive_check(clientSock);
	}

	printf(PRINT_COLOR_YELLOW"conexion perdida con cliente: %d\n"PRINT_COLOR_RESET,clientSock);
	connection_close(clientSock);
}





int main(void){
	sockets_sem = (sem_t*) malloc(sizeof(sem_t));
	sem_init(sockets_sem,1,0);

	printf(PRINT_COLOR_BLUE"iniciando servidor... \n"PRINT_COLOR_RESET);

	int server_socket = connection_start_server("127.0.0.1","4449");


	if(server_socket<0){

		connection_server_error(server_socket);

	}else{

		printf(PRINT_COLOR_GREEN "Servidor iniciado \n" PRINT_COLOR_BLUE "Esperando conexiones...\n" PRINT_COLOR_RESET);

		int status = connection_handler(server_socket,listenner,sockets_sem);

		if(server_socket<0)
			connection_server_error(status);


	}

	readline("presione enter para salir");

	return 1;

}
