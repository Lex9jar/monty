#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack,
 * accordingly
 * @stack: pointer to a stack
 * @line_number: current command line in monty_file
 *
 * Return: void.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	bus._FIFO = 0;
}

/**
 * _queue - Sets the format of the data to a queue
 * @stack: pointer to a stack
 * @line_number: current command line in monty_file
 *
 * Return: void.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	bus._FIFO = 1;
}
