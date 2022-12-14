#include "monty.h"

/**
 * sub - add node
 * @stack: pointer to the tp of stack
 * @line_number: number of line
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int substrac;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L<line_number>: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	substract = temp->n - temp->next->n;
	temp->next->n = subbstrac;

	*stack = temp->next;

	free(temp);
}

