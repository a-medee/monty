#include "monty.h"


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
		fprintf(stderr, "%s %u %s\n", "L", line_number, buf);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	first = get_dnode_at_index((*stack), 0);
	second = get_dnode_at_index((*stack), 1);

	second->n = second->n + first->n;
	op_code_pop(stack, line_number);
}

/**
 * get_dnode_at_index -  a function that returns the nth node of a
 * stack_t
 * @head: a pointer to the first element of our stack
 * @index: is the index of the node, starting at 0
 *
 * Return: if the node does not exist, return NULL, the node otherwise
 */

stack_t *get_dnode_at_index(stack_t *head, unsigned int index)
{
	unsigned int i, size = (unsigned int)stack_t_len(head);
	stack_t *firstnode = head, *node_to_be_returned;

	if (head && (index <= size))
	{
		for (i = 0; i < index; i++)
		{
			head = head->next;
		}
		node_to_be_returned = head;
		head = firstnode;
		return (node_to_be_returned);
	}

	return (NULL);
}

/**
 * op_code_nop - do nothing
 * @stack: the stack head
 * @line_number: file line number
 *
 * Return: a void element
 */

void op_code_nop(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number) {}

/**
 * free_dlist - a function that frees a dlistint_t list
 * @head: the head of the list to be freed
 *
 * Return: a type void
 */

void free_dlist(stack_t *head)
{
	stack_t *torm;

	while (head)
	{
		torm = head;
		head = head->next;
		free(torm);
	}
	head = NULL;
}
