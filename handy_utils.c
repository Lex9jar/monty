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
