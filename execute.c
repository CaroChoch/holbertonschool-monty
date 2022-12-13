#include "monty.h"
#define LIMIT 100

/**
 * exec - This function parse lines from a text.m
 * @monty_file: File with monty steps to execute.
 * @op_functions: All the list-displays from functions.
 * Return: nothing
 *
 */

void exec(FILE *monty_file, instruction_t op_functions[])
{
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char *token = NULL;
	char line[LIMIT];
	int i, enter, stack_case = 0;

	while (fgets(line, sizeof(line), monty_file))
	{
		enter = 0;
		token = strtok(line, LIMITERS);

		if (token)
		{
			for (i = 0; i < 18; i++)
			{
				if (strcmp(token, op_functions[i].opcode) == 0)
				{
					if (i == 0)
					{
						token = strtok(NULL, LIMITERS);
						token_error(stack, line_number, monty_file, token);
						is_number(stack, line_number, token, monty_file);
						n = atoi(token);
					}
					handle1(&stack, line_number, monty_file, i);
					if (stack_case == 1 && i == 0)
						i = 17;
					if (i == 16)
						stack_case = 1;
					else if (i == 15)
						stack_case = 0;
					op_functions[i].f(&stack, line_number);
					enter = 1;
				}
			}
			comment(stack, line_number, token, monty_file, enter);
		}
		line_number++;
	}
	frees(stack);
}
