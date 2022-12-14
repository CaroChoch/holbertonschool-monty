#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element of the
 * stack
 * @stack: pointer to the tp of stack
 * @line_number: number of line
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int divide;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	divide = temp->next->n / temp->n;
	temp->next->n = divide;

	*stack = temp->next;

	free(temp);
}
