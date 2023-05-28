#include "monty.h"
#include <stdio.h>

/**
 * op_code_pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_pchar(stack_t **stack, unsigned int line_number)
{
	char buf[90] = "can't pchar, value out of range";
	char buf_1[90] = "can't pchar, stack empty";
	unsigned int val;
	size_t size = stack_t_len(*stack);

	if (size == 0)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf_1);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;

	if ((63 < val) && (64 > val || 127 < val))
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * op_code_pstr - prints the string starting at the top of
 * the stack, followed by a new line.
 * followed by a new line.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_pstr(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	size_t size = stack_t_len(*stack);
	stack_t *st = (*stack);
	unsigned int val;

	if (size != 0)
	{
		val = st->n;
		while (st && (st->n != 0))
		{
			if ((63 < val) && (64 > val ||  127 < val))
				break;
			fprintf(stdout, "%c", st->n);
			st = st->next;
			if (st)
				val = st->n;
		}
	}
	fprintf(stdout, "\n");
}

/**
 * op_code_rotr - rotates the stack to the bottom.
 * followed by a new line.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_rotr(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_t_len(*stack);
	stack_t *st = (*stack);

	if (size == 0)
	{
		fprintf(stderr, "\n");
	}

	while (st && (st->n != 0))
	{
		op_code_pchar(&st, line_number);
		st = st->next;
	}
}

/**
 * op_code_rotl - rotates the stack to the top.
 * followed by a new line.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_rotl(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	size_t size = stack_t_len(*stack);
	stack_t *last, *first;

	if (*stack)
	{
		if (size != 1)
		{
			last = get_dnode_at_index(*stack, size - 1);
			first = (*stack);
			(*stack) = (*stack)->next;
			(*stack)->prev = NULL;
			last->next = first;
			first->prev = last;
			first->next = NULL;
		}
	}
}
