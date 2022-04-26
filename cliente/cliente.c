/*
 * cliente.c
 *
 *  Created on: 5 ago. 2021
 *      Author: utnso
 */


#include <utils/connection/connection.h>
#include <utils/globals.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <pthread.h>

int main(void){

	int server_socket = connection_connect("127.0.0.1","4449");

	if(server_socket >0){
		printf(PRINT_COLOR_GREEN "conexion aceptada\n" PRINT_COLOR_RESET);

		int sender;
		char * message;
		connection_packet* p;
		while(1){

			message = readline(PRINT_COLOR_BLUE"operacion:"PRINT_COLOR_RESET);

			if(strcmp(message,"suma") == 0){
				p = connection_packet_create_with_opCode(OP_SUMA);

				message = readline(PRINT_COLOR_MAGENTA"numero a:"PRINT_COLOR_RESET);
				sender = atoi(message);
				connection_packet_add(p,&sender,sizeof(int));

				message = readline(PRINT_COLOR_MAGENTA"numero b:"PRINT_COLOR_RESET);
				sender = atoi(message);
				connection_packet_add(p,&sender,sizeof(int));

				connection_packet_send(p,server_socket);
				connection_packet_destroy(p);
			}
			if(strcmp(message,"resta") == 0){
				p = connection_packet_create_with_opCode(OP_RESTA);

				message = readline(PRINT_COLOR_MAGENTA "numero a:" PRINT_COLOR_RESET);
				sender = atoi(message);
				connection_packet_add(p,&sender,sizeof(int));

				message = readline(PRINT_COLOR_MAGENTA "numero b:" PRINT_COLOR_RESET);
				sender = atoi(message);
				connection_packet_add(p,&sender,sizeof(int));

				connection_packet_send(p,server_socket);
				connection_packet_destroy(p);
			}
			if(strcmp(message,"mensaje") == 0){
				p = connection_packet_create_with_opCode(OP_MENSAJE);

				message = readline(PRINT_COLOR_MAGENTA "mensaje:" PRINT_COLOR_RESET);
				connection_packet_add_with_size(p,message,strlen(message)+1);

				connection_packet_send(p,server_socket);
				connection_packet_destroy(p);
			}

		}
	}else{
		printf(PRINT_COLOR_RED"conexion rechazada\n"PRINT_COLOR_RESET);

	}

	readline("presione enter para salir");

}
