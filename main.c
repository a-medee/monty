#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/** main - Program entry point
 * @argc: arguments number to the program
 * @argv: arguments passed to the program
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{

	FILE *op_file;
	char *input, *opcode;
	char file_buffer[1024];
	unsigned int pos = 0;
	o = 9;

        if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	if ((op_file = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "%s %s\n", "Error: Can't open file", argv[1]);
		exit(EXIT_FAILURE);
	}

	while((input = s_gets(file_buffer, 1024, op_file)))
	{
		if (*input == '\0')
			continue;
		opcode = strtok(file_buffer, " ");
		printf("%s\n", opcode);
		check_valid_op(opcode, pos++);
	}
	return (0);
}
