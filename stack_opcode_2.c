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
