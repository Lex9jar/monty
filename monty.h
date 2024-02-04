#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous elements of the stack (or queue)
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
 * for stack, queue, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - a struct that carries all data for the program
 *
 * @line_number: Keep track of current command line in a monty file
 * @size: keep track of the number of nodes added to stack
 * @_FIFO: For switching between modes (stack/queue)
 * @stack: pointer to a stack_t stack
 * @lineptr: pointer to a read line from a monty file
 * @monty_file: pointer to a monty file (.m)
 * @opcode: pointer to a command to execute
 * @arg: argument for opcode
 *
 * Description: A structure of all the handy datas in the program
 * we will need as we progress.
 *
 */
typedef struct bus_s
{
	unsigned int line_number;
	int size;
	int _FIFO;
	stack_t *stack;
	char *lineptr;
	FILE *monty_file;
	char *opcode;
	char *arg;
} bus_t;
extern bus_t bus;

/* = > = > = > EXECUTION FUNCTIONS < = < = < = */
void get_opcodes(void);
void execute(void);

/* = > = > = > STACK PRIMARY FUNCTIONS < = < = < = */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_nnumber);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

/* = > = > = > HANDY_UTILS < = < = < = */
int not_number(char *token);
void add_at_beg(void);
void add_at_end(void);

/* = > = > = > FREE_FUNCTION < = < = < = */
void free_bus(void);
void free_stack(stack_t **stack);

#endif /* _MONTY_H_ */
