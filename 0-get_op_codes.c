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
				    {"nop", op_code_nop},   {NULL, NULL}};
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
