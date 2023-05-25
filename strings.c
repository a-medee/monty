#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * s_gets - take string input
 * @str: string input
 * @size: the number of bytes to from from the defined string
 * @stream: file stream to read from
 *
 * Return: a pointer-to-char
 */

char *s_gets(char *str, int size, FILE *stream)
{
	char *getptr;
	int i = 0;

	if (str)
	{
		getptr = fgets(str, size, stream);
		if (getptr)
		{
			while (str[i] != '\0' && str[i] != '\n')
			{
				i++;
			}

			if (str[i] == '\n')
				str[i] = '\0';
			else
			{
				while (getchar() != '\n')
					continue;
			}
		}
		return (getptr);
	}

	return (NULL);
}

/**
 * check_valid_op - check for valid opcode
 * @opcode: opcode to check
 * @op_file: file stream
 *
 * Return an unsigned int value
 */

unsigned int check_valid_op(char *opcode, unsigned int pos)
{
	const char *op_codes[19] = {"push","pall", "pint",
				    "pop", "swap","add", "sub",
				    "nop", "div","mul", "mod",
				    "pchar","pstr", "rotl", "rotr",
				    "rotr", "stack", "queue", NULL};
	int i = 0;
	while (op_codes[i])
	{
		if (strcmp(op_codes[i], opcode) == 0)
			return (pos);
		i++;
	}

	if (i == 18)
	{
		fprintf(stderr, "%s %u %s %s\n", "L", pos, "unknown instruction",
			opcode);
		exit(EXIT_FAILURE);
	}

	return (pos);
}
