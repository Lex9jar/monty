#include "monty.h"

/**
 * _mod - Computes the rest of the devision of the second top element
 * of the stack by the top element of the stack
 * @stack: A pointer to a stack
 * @line_number: current command line number in monty_file
 *
 * Return: void.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int product;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = product;
}

/**
 * _pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: pointer to a stack
 * @line_number: current command line number in monty_file
 *
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int chr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	chr = (*stack)->n;
	if (chr < 0 || chr > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	write(1, &chr, 1);
}
