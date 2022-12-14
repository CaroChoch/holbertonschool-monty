#include "monty.h"

/**
 * push - Function that pushes an element at the top of the stack.
 * @stack: top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;
	int index;

	num = strtok(NULL, DELIMS);
	if (num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (index = 0; num[index] != '\0'; index++)
	{
		if (num[index] == '-')
			index++;
		if (isdigit(num[index]) == 0)
		{
			fprintf(stderr, "L%u: usage: push interger\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(num);
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;

	*stack = node;
}

