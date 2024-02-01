#include "monty.h"

/**
 * push - Adds a new data to stack.
 * @stack: A doubly linked list
 * @line_number: Line number in a monty file
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (bus.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}
	if (not_number(bus.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_bus();
		fclose(bus.monty_file);
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(bus.arg);
	new->next = NULL;

	if (*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
}

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
#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: A doubly linked list
 * @line_number: Current command line index in monty file
 *
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(del);
	del = NULL;
}
