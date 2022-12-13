#include "monty.h"

cmd_t cmd = {NULL, NULL};
/**
 * exec - function that read the file and execute the monty byte
 *@argv: the file ;
 */
void exec(char *argv)
{
	int c_line = 0, r = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *stack = NULL;

	/** open file mod read in global variable*/
	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.buffer, &bufsize, cmd.fd) != -1)
		{
			c_line++;
			token = strtok(cmd.buffer, LIMITERS);
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')/** is comment*/
				continue;
			val = strtok(NULL, LIMITERS);
			r = get_op(&stack, token, val, c_line);
			if (r == 1) /** get_op return 1 when the value is not digit */
				push_error(cmd.fd, cmd.buffer, stack, c_line); /** print push error*/
			else if (r == -1) /** get_op return -1 if not the instruction */
				hand_error(cmd.fd, cmd.buffer, stack, token, c_line);
					/**print instruction error*/
		}
		free(cmd.buffer);
		_free(stack);/** free all*/
		fclose(cmd.fd); /** close file*/
	}
	else
	{
		/** print open error*/
		open_error(argv);

	}
}

/**
 * get_op - function that get the option function
 * @stack: stack or queue
 * @arg: commande
 * @val: value
 * @line_number: iline number
 * Return: 0 in success 1 and -1 error
 */
int get_op(stack_t **stack, char *arg, char *val, unsigned int line_number)
{
	int i = 0, value;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"linking", linking},
		{"add", add},
		{"breaking", breaking},
		{"increase ", increase},
		{"enter", enter},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(val) == 1)
					value = atoi(val);
				else
					return (1);/** if not digit*/
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (-1);/** if not the commande*/

	return (0);
}

/**
 * clean_stack - Free all and close files
 * @stack: Stack
 */
void clean_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;

		free(temp);
	}
		fclose(cmd.fd);
		free(cmd.buffer);
}