#include "monty.h"

/**
 * not_number - Checks if a token content characters otherthan digits
 * @token: token for validation
 *
 * Return: 1 if it contain character(s) otherthan digits, otherwise 0.
 */
int not_number(char *token)
{
	if (*token == '-')
		token++;

	while (*token)
	{
		/* check if there's a non digit character */
		if (!isdigit(*token))
			return (1);
		token++;
	}

	return (0);
}

/**
 * add_at_beg - Adds a new node at the beginning of a stack
 *
 * Return: void.
 */
void add_at_beg(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_bus();
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(bus.arg);

	if (bus.stack == NULL)
		new->next = NULL;
	else
		new->next = bus.stack;

	bus.stack = new;
	bus.size++;
}

/**
 * add_at_end - Adds a new node at the end of a stack
 *
 * Return: void.
 */
void add_at_end(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_bus();
		exit(EXIT_FAILURE);
	}

	new->n = atoi(bus.arg);
	new->next = NULL;

	if (bus.stack == NULL)
	{
		new->prev = NULL;
		bus.stack = new;
		bus.last = new;
	}
	else
	{
		bus.last->next = new;
		new->prev = bus.last;
		bus.last = new;
	}
	bus.size++;
}
