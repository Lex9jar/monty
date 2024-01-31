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
 * @stack: A linear data structure
 * @line_number: Carries the current line number of the monty_file
 * @monty_file: Pointer to an opened monty file
 * @lineptr: Line read from monty_file
 * @opcode: An array of a command and it argument
 *
 * Description: A structure of all the vital datas in the program
 * we will need as we progress.
 *
 */
typedef struct bus_s
{
	unsigned int line_number;
	stack_t *stack;
	char *lineptr;
	FILE *monty_file;
	char *opcode[2];
} bus_t;
extern bus_t bus;

/* = > = > = > EXECUTION FUNCTIONS < = < = < = */
void get_opcodes(void);
void execute(void);

/* = > = > = > STACK PRIMARY FUNCTIONS < = < = < = */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* = > = > = > HANDY_UTILS < = < = < = */
int not_number(char *token);

/* = > = > = > FREE_FUNCTION < = < = < = */
void free_bus(void);
void free_stack(stack_t **stack);

#endif /* _MONTY_H_ */