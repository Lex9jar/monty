#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: A doubly linked list
 * @line_number: command line number in the monty file
 *
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * nop - Does nothing
 * @stack: A doubly linked list
 * @line_number: Command line number in monty file
 *
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - substracts the top element of the stack from the second
 * top element of the stack
 * @stack: A doubly linked list
 * @line_number: Command line number in monty file
 *
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int dif;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	dif = (*stack)->n - (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = dif;
}
