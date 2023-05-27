#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/cdefs.h>

extern int value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_op_codes(char *))(stack_t **, unsigned int);
void op_code_push(stack_t **, unsigned int);
void op_code_pall(stack_t **, unsigned int);
void op_code_pint(stack_t **, unsigned int);
void op_code_pop(stack_t **, unsigned int);
void op_code_swap(stack_t **, unsigned int);
void op_code_add(stack_t **, unsigned int);
void __attribute__((unused))op_code_nop(stack_t **, unsigned int);

unsigned int check_valid_op(char *, unsigned int, stack_t **);
char *s_gets(char *, int, FILE *);
size_t stack_t_len(const stack_t *h);
stack_t *get_dnode_at_index(stack_t *head, unsigned int index);
void free_dlist(stack_t *head);

#endif /** _MONTY_H_ */
