#include "monty.h"

/**
 * get_opcode - Fetches the approprate function for a particular
 * command
 *
 * Return: void.
 */
void get_opcodes(void)
{
	char *commands[] = {"push", "pall", NULL};
	int i, flg = 0;

	bus.opcode[0] = strtok(bus.lineptr, " \t\r\n");
	while (bus.opcode[0])
	{
		for (i = 0; commands[i]; i++)
		{
			if ((strcmp((const char*)bus.opcode[0],
				(const char*)commands[i])) == 0)
			{
				bus.opcode[1] = strtok(NULL, " \t\v\n");
				flg = 1;
				break;
			}
		}
		if (flg == 1)
			break;
		bus.opcode[0] = strtok(NULL, " \t\r\n");
	}
	if (flg == 1)
		execute();
}

/**
 * execute - Executes a command
 *
 * Return: void.
 */
void execute(void)
{
	instruction_t fetch[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (fetch[i].opcode != NULL)
	{
		if ((strcmp(fetch[i].opcode, bus.opcode[0])) == 0)
		{
			fetch[i].f(&(bus.stack), bus.line_number);
			return;
		}
		i++;
	}

	if (fetch[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instructions %s\n", bus.line_number, bus.opcode[0]);
		free_bus();
		exit(EXIT_FAILURE);
	}
}
