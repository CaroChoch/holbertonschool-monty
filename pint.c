#include "monty.h"

/**
 * pint - prints the value at the top
 * @stack: pointer to the head
 * @line_number: number of line
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number), exit(EXIT_FAILURE);

	printf("%d\n", (*stack)->n);
}
