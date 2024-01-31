#include "monty.h"

/**
 * push - Adds a new data to stack
 * @stack: A doubly linked list
 * @line_number: Line number in a monty file
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_bus();
		fclose(bus.monty_file);
		exit(EXIT_FAILURE);
	}

	if (not_number(bus.opcode[1]))
	{
		fprintf(stderr, "l%u: usage: push integer\n", line_number);
		free(new);
		free_bus();
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(bus.opcode[1]);
	new->next = *stack;

	*stack = new;
}

/**
 * not_number - Checks if a token content characters otherthan digits
 * @token: token for validation
 *
 * Return: 1 if it contain character(s) otherthan digits, otherwise 0.
 */
int not_number(char *token)
{
	int i;

	for (i = 0; token[i]; i++)
		if (!isdigit(token[i]))
			return (1);
	return (0);
}
