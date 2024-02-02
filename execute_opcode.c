#include "monty.h"

/**
 * get_opcodes - Fetches the approprate function for a particular
 * command
 *
 * Return: void.
 */
void get_opcodes(void)
{
	char *commands[] = {"push", "pall", "pint",
			"pop", "swap", "add",
			"nop", "sub", "div",
			"mul", "mod", "pchar",
			"pstr", "rotl", "rotr",
			NULL};
	int i, flg = 0;

	bus.opcode = strtok(bus.lineptr, " \t\n");
	if (bus.opcode == NULL || (strchr((const char *)bus.opcode, '#')))
		return;

	for (i = 0; commands[i]; i++)
	{
		if ((strcmp(bus.opcode, commands[i])) == 0)
		{
			bus.arg = strtok(NULL, " \t\n");
			flg = 1;
			break;
		}
	}

	if (flg)
		execute();
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				bus.line_number, bus.opcode);
		free_bus();
		exit(EXIT_FAILURE);
	}


}

/**
 * execute - Executes a command
 *
 * Return: void.
 */
void execute(void)
{
	instruction_t fetch[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (fetch[i].opcode != NULL)
	{
		if ((strcmp(fetch[i].opcode, bus.opcode)) == 0)
		{
			fetch[i].f(&(bus.stack), bus.line_number);
			return;
		}
		i++;
	}
}
