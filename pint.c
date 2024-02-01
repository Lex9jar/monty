#include "monty.h"

/**
 * pint - Prints the topmost node of a list
 * @stack: A doubly linked list
 * @line_number: Line number in monty file
 *
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
