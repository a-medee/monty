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
 * @pos: line number position
 * @stack: the stack head
 *
 * Return: an unsigned int value
 */

unsigned int check_valid_op(char *opcode, unsigned int pos, stack_t **stack)
{
	const char *op_codes[19] = {"push", "pall", "pint", "pop", "swap", "add",
			"sub", "nop", "div", "mul", "mod", "pchar", "pstr", "rotl",
			"rotr", "rotr", "stack", "queue", NULL};
	int i = 0;
	char *str_ = strtok(NULL, " ");

	while (op_codes[i])
	{
		if ((strcmp(op_codes[i], opcode) == 0))
		{
			if (strcmp(op_codes[i], "push") == 0)
			{
				if ((str_ == NULL) ||
				    ((strcmp(str_, "0") != 0) &&
				     (atoi(str_) == 0)))
				{
					fprintf(stderr, "%s%u: %s\n", "L", pos,
						"usage: push integer");
					free_dlist(*stack);
					exit(EXIT_FAILURE);
				}
				value = atoi(str_);
			}
			return (pos);
		}
		i++;
	}

	if (i == 18)
	{
		fprintf(stderr, "%s%u: %s %s\n", "L", pos, "unknown instruction",
			opcode);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}
	return (pos);
}
