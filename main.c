#include "monty.h"

bus_t bus = {0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};

/**
 * main - An interpreter for Monty ByteCodes files.
 * @argc: Number of arguments passed
 * @argv: Array of arguments passed
 *
 * Return: 0 upon Success.
 */
int main(int argc, char *argv[])
{
	ssize_t r = 1;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bus.monty_file = fopen(argv[1], "r");
	if (bus.monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (r != -1)
	{
		bus.line_number++;
		bus.lineptr = NULL;
		r = getline(&(bus.lineptr), &n, bus.monty_file);
		if (r > 0)
			get_opcodes();
		free(bus.lineptr);
	}
	free_stack(&(bus.stack));
	fclose(bus.monty_file);

	return (0);
}
