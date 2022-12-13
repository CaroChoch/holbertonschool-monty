#include "monty.h"

int num;
/**
 * push - Function that pushes an element at the top of the stack.
 * @stack: top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = newnode(num);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
