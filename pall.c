#include "monty.h"

/**
 * pall - Prints a stack
 * @stack: A doubly linked list
 * @line_number: Current file line
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (ptr == NULL)
		return;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
