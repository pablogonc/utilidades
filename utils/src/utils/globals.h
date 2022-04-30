/*
 * globals.h
 *
 *  Created on: 8 ago. 2021
 *      Author: utnso
 */

#ifndef SRC_UTILS_GLOBALS_H_
#define SRC_UTILS_GLOBALS_H_

#define PRINT_COLOR_RED     "\x1b[31m"
#define PRINT_COLOR_GREEN   "\x1b[32m"
#define PRINT_COLOR_YELLOW  "\x1b[33m"
#define PRINT_COLOR_BLUE    "\x1b[34m"
#define PRINT_COLOR_MAGENTA "\x1b[35m"
#define PRINT_COLOR_CYAN    "\x1b[36m"
#define PRINT_COLOR_RESET   "\x1b[0m"

#include <commons/collections/list.h>
#include <stdint.h>
typedef enum //codigos de operaciones servidor
{
	OP_LISTA_INSTRUCCIONES,
	OP_NUEVO_PCB
}op_code;

typedef enum //instrucciones
{
	NO_OP,
	IO,
	READ,
	COPY,
	WRITE,
	EXIT
}InstructionID;

typedef struct {
	InstructionID id;
	int cantidadParametros;
	int* parametros;
}Instruccion;

typedef struct{
	uint32_t id;
	uint32_t tamanio;
	t_list* instruccioes;
	uint32_t program_counter;
	uint32_t tabla_paginas;
	uint32_t estimacion_rafaga;

}PCB;

#endif /* SRC_UTILS_GLOBALS_H_ */
