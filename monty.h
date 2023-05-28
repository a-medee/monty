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
	void (*f)(stack_t **, unsigned int);
} instruction_t;

/** 0-get_op_codes */
void (*get_op_codes(char *))(stack_t **, unsigned int);

/** 0-op_codes_func.c */
void op_code_push(stack_t **, unsigned int);
void op_code_pall(stack_t **, unsigned int);
void op_code_pint(stack_t **, unsigned int);
void op_code_pop(stack_t **, unsigned int);
void op_code_swap(stack_t **, unsigned int);

/** 2-op_codes_func.c */
void op_code_add(stack_t **, unsigned int);
void op_code_sub(stack_t **, unsigned int);
void op_code_div(stack_t **, unsigned int);
void op_code_mod(stack_t **, unsigned int);
void op_code_mul(stack_t **, unsigned int);


/** strings.c */
unsigned int check_valid_op(char *, unsigned int, stack_t **);
char *s_gets(char *, int, FILE *);

/** 1-op_codes_func.c */
size_t stack_t_len(const stack_t *);
stack_t *get_dnode_at_index(stack_t *, unsigned int);
void free_dlist(stack_t *);
void __attribute__((unused))op_code_nop(stack_t **, unsigned int);

/** 3-op_codes_func.c */
void op_code_pchar(stack_t **, unsigned int);
void op_code_pstr(stack_t **, unsigned int);
void op_code_rotr(stack_t **, unsigned int);
void op_code_rotl(stack_t **, unsigned int);

/** 4-op_codes_func.c */
void op_code_stack(stack_t **, unsigned int);
void op_code_queue(stack_t **, unsigned int);
#endif /** _MONTY_H_ */
