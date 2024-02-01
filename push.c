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

	printf("HERE AT PUSH\n");
	if (bus.opcode[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}
	if (not_number(bus.opcode[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_bus();
		fclose(bus.monty_file);
		exit(EXIT_FAILURE);
	}

	if (*stack)
		(*stack)->prev = new;
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
	{
		if (token[0] == '-')
			i++;
		if (token[i] < 48 || token[i] > 57)
			return (1);
	}
	return (0);
}
