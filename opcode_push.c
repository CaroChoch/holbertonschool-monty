#include "monty.h"

/**
 * op_push - Function that pushes an element to the stack.
 *
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number.
 * Return: Nothing.
 *
 */

void op_push(stack_t **stack, unsigned int line_number)
{
        stack_t *new_node;
        (void) line_number;

        new_node = malloc(sizeof(stack_t));

        if (new_node == NULL)
                fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

        new_node->n = n;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (*stack != NULL)
        {
                (*stack)->prev = new_node;
                new_node->next = *stack;
        }

        *stack = new_node;
}
