#include "monty.h"
#include <stdio.h>

/**
 * op_code_stack - sets the format of the data to a stack (LIFO).
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack) != NULL)
	{
		if (((*stack)->n) != value)
			op_code_rotr(stack, line_number);
	}
}

/**
 * op_code_queue - sets the format of the data to a stack (FIFO).
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_queue(stack_t **stack, unsigned int line_number)
{
	if ((*stack) != NULL)
	{
		if (((*stack)->n) == value)
			op_code_rotr(stack, line_number);
	}
}
