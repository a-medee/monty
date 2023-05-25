#include "monty.h"
#include <stdlib.h>
#include <sys/cdefs.h>

/**
 * op_code_push - push an element to the stack
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

        if (new)
	{
		new->n = o;
		new->next = (*stack);
		new->prev = NULL;

                if ((*stack) != NULL)
			(*stack)->prev = new;
		(*stack) = new;
	}
}
