#include "monty.h"

/**
 * _free - This function frees stack
 * @stack: stack.
 */

void _free(stack_t *stack)
{
	stack_t *delete = NULL;

	while (stack)
	{
		delete = stack->next;
		free(delete);
		stack = delete;
	}
}
