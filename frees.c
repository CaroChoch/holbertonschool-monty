#include "monty.h"

/**
 * frees - This function frees stack
 * @stack: stack.
 */

void _free(stack_t *stack)
{
	stack_t *delete = NULL;

	while (stack)
	{
		delete = stack;
		stack = stack->next;
		free(delete);
	}
}
