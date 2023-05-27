#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Program entry point
 * @argc: arguments number to the program
 * @argv: arguments passed to the program
 *
 * Return: 0 on success
 */

int value = 0;

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *op_file;
	char *input, *opcode;
	char file_buffer[1024];
	unsigned int pos = 1;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	op_file = fopen(argv[1], "r");
	if (op_file == NULL)
	{
		fprintf(stderr, "%s %s\n", "Error: Can't open file", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((input = s_gets(file_buffer, 1024, op_file)))
	{
		if (*input == '\0')
			continue;
		opcode = strtok(input, " ");
		get_op_codes(opcode)(&stack, check_valid_op(opcode, pos++, &stack));
	}
	fclose(op_file);
	free_dlist(stack);
	return (0);
}
