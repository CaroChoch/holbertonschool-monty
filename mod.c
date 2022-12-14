#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * the stack
 * @stack: pointer to the tp of stack
 * @line_number: number of line
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int modulo;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	modulo = temp->next->n % temp->n;
	temp->next->n = modulo;

	*stack = temp->next;

	free(temp);
}

