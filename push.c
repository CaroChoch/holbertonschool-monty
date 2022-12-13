#include "monty.h"

/**
 * push - Function that pushes an element at the top of the stack.
 * @stack: top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;
    int num;

	new = new_Node(num);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
