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

typedef enum //codigos de operaciones servidor
{
	OP_SUMA,
	OP_RESTA,
	OP_MENSAJE
}op_code;



#endif /* SRC_UTILS_GLOBALS_H_ */
