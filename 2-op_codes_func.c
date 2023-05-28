#include "monty.h"

/**
 * op_code_div -  divides the second top element of
 * the stack by the top element of the stack.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	char buf[90] = "can't div, stack too short";
	char buf_1[90] = "division by zero";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	if (first->n == 0)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf_1);
		free_dlist(*stack);
		exit(EXIT_FAILURE);

	}
	second->n = second->n / first->n;
	op_code_pop(stack, line_number);
}

/**
 * op_code_mul - multiply the top element of
 * the stack by the second top element of the stack.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	char buf[90] = "can't mul, stack too short";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	second->n = second->n * first->n;
	op_code_pop(stack, line_number);
}

/**
 * op_code_mod - computes the rest of the division of
 * the second top element of the stack by the top element of the stack
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	char buf[90] = "can't mod, stack too short";
	char buf_1[90] = "division by zero";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	if (first->n == 0)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf_1);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	second->n = second->n % first->n;
	op_code_pop(stack, line_number);
}

/**
 * op_code_add - push an element to the stack
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	char buf[90] = "can't add, stack too short";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	second->n = second->n + first->n;
	op_code_pop(stack, line_number);
}

/**
 * op_code_sub - subtracts the top element of
 * the stack from the second top element of the stack.
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	char buf[90] = "can't sub, stack too short";
	size_t size = stack_t_len(*stack);

	if (size < 2)
	{
		fprintf(stderr, "%s%u: %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	second->n = second->n - first->n;
	op_code_pop(stack, line_number);
}
