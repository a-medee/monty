#include "monty.h"

/**
 * op_code_push - push an element to the stack
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_push(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new)
	{
		new->n = value;
		new->next = (*stack);
		new->prev = NULL;

		if ((*stack) != NULL)
			(*stack)->prev = new;
		(*stack) = new;
	}
	else
	{
		fprintf(stderr, "%s\n", "Error: malloc failed");
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_code_pall - display the stack
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_pall(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	stack_t *new = (*stack);

	while (new)
	{
		fprintf(stdout, "%d\n", new->n);
		new = new->next;
	}
}

/**
 * op_code_pint - display the top most element
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_pint(stack_t **stack, unsigned int line_number)
{
	char buf[90] = "can't pint, stack empty";

	if (!(*stack))
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);

	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * op_code_pop - removes the top element of the stack.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = (*stack);
	char buf[90] = "can't pop an empty stack";

	if (!(*stack))
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	free(node);
}

/**
 * op_code_swap - swaps the top two elements of the stack.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *last_;
	char buf[90] = "can't swap, stack too short";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	if (size == 2)
	{
		last_ = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->next = last_;
		(*stack)->prev = NULL;
		last_->next = NULL;
		last_->prev = (*stack);
	}
	else
	{
		last_ = (*stack);
		(*stack) = (*stack)->next;
		last_->next = (*stack)->next;
		last_->prev = (*stack);
		((*stack)->next)->prev = last_;
		(*stack)->next = last_;
		(*stack)->prev = NULL;
	}
}
