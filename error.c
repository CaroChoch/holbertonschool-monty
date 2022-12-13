#include "monty.h"

/**
 * token_error - Checks if token value is NULL.
 *
 * @stack: Stack.
 * @number: Line number.
 * @file: Monty file.
 * @tok: Number.
 *
 * Return: Nothing.
 */

void token_error(stack_t *stack, unsigned int number, FILE *file, char *tok)
{
	if (!tok)
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		frees(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
