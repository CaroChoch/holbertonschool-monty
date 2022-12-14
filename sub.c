#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element of
 * the stack
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	substrac = temp->n - temp->next->n;
	temp->next->n = substrac;

	*stack = temp->next;

	free(temp);
}

