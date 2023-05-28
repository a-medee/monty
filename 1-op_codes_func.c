#include "monty.h"

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

/**
 * stack_t_len - returns the number of elements in a
 * linked srack_t list.
 * @h: a head to our doubly linked list
 *
 * Return: the number of nodes in a doubly linked list
 */

size_t stack_t_len(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
