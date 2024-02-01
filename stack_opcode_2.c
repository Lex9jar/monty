#include "monty.h"

/**
 * _add - Adds the top two elements of the stack
 * @stack: A doubly linked list
 * @line_number: command line number in the monty file
 *
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _nop - Does nothing
 * @stack: A doubly linked list
 * @line_number: Command line number in monty file
 *
 * Return: void.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - substracts the top element of the stack from the second
 * top element of the stack
 * @stack: A doubly linked list
 * @line_number: Command line number in monty file
 *
 * Return: void.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int dif;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	dif = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = dif;
}

/**
 * _div - Divides the second top element of the stack by the top
 * element of the stack
 * @stack: A doubly linked list
 * @line_number: Command line number in monty file
 *
 * Return: void.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack tooo short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = quotient;
}
