#include "monty.h"

/**
 * is_number - Checks if a string is a number.
 *
 * @token: String to compare.
 * @stack: Stack.
 * @lnumber: Line number.
 * @mfile: Monty file.
 *
 * Return: Nothing.
 */

void is_number(stack_t *stack, unsigned int lnumber, char *token, FILE *mfile)
{
	int i = 0;

	if (token[0] == '-' && token[1])
		i++;

	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", lnumber);
			frees(stack);
			fclose(mfile);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
