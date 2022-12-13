#include "monty.h"

/**
 * frees - This function frees memory
 * @stack: stack.
 * Return: Nothing.
 */

void frees(stack_t *stack)
{
	stack_t *delete = NULL;

	while (stack)
	{
		delete = stack;
		stack = stack->next;
		free(delete);
	}
}
