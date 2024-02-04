#include "monty.h"

/**
 * _push - Adds a new data to stack.
 * @stack: pointer to a stack
 * @line_number: current command line number of monty_file
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (bus.arg == NULL || not_number(bus.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_bus();
		exit(EXIT_FAILURE);
	}

	if (bus._FIFO)
		add_at_end();
	else
		add_at_beg();
}

/**
 * _pall - Prints a stack
 * @stack: pointer to a stack
 * @line_number: Current command line number of monty_file
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
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
 * _pint - Prints the topmost node of a list
 * @stack: pointer to a stack
 * @line_number: current command line number of monty_file
 *
 * Return: void.
 */
void _pint(stack_t **stack, unsigned int line_number)
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
 * _pop - Removes the top element of the stack
 * @stack: pointer to a stack
 * @line_number: Current command line number in monty_file
 *
 * Return: void.
 */
void _pop(stack_t **stack, unsigned int line_number)
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
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to a stack
 * @line_number: current command line number in monty_file
 *
 * Return: void.
 */
void _swap(stack_t **stack, unsigned int line_number)
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
