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
	bus.size++;
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

	if (*stack == NULL)
		return;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

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

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		free(del);
	}
	bus.size--;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: A doubly linked list
 * @line_number: current command line in monty file
 *
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *tmp;

	if (bus.size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->next;
	first = *stack;
	second = (*stack)->next;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (bus.size == 2)
		first->next = NULL;
	else
	{
		first->next = tmp;
		tmp->prev = first;
	}
	
	*stack = second;
}
