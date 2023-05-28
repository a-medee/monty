#include "monty.h"

/**
 * get_op_codes - select the operation that the user asked for
 * @opcode: opcode for our functions
 *
 * Return: a type void pointer to function
 */

void (*get_op_codes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes [] = {{"push", op_code_push}, {"pall", op_code_pall},
				    {"pint", op_code_pint}, {"pop", op_code_pop},
				    {"swap", op_code_swap}, {"add", op_code_add},
				    {"nop", op_code_nop}, {"sub", op_code_sub},
				    {"div", op_code_div}, {"mod", op_code_mod},
				    {"mul", op_code_mul}, {"pchar", op_code_pchar},
				    {"pstr", op_code_pstr}, {"rotr", op_code_rotr},
				    {"rotl", op_code_rotl}, {NULL, NULL}};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}

	return (NULL);
}
