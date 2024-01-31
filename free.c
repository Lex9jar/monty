#include "monty.h"

/**
 * free_bus - Frees a bus structure
 *
 * Return: void.
 */
void free_bus(void)
{
	if (bus.stack != NULL)
		free_stack(&(bus.stack));
	if (bus.lineptr != NULL)
		free(bus.lineptr);

	fclose(bus.monty_file);
}

/**
 * free_stack - Frees a doubly linked list.
 *
 * Return: void.
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;

	ptr = *stack;
	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}
