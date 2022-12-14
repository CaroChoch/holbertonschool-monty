#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element of
 * the stack
 * @stack: pointer to the tp of stack
 * @line_number: number of line
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mult;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	mult = temp->n * temp->next->n;
	temp->next->n = mult;

	*stack = temp->next;

	free(temp);
}
