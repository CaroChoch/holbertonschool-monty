#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 * main - the main function of the monty program
 * @argc: the argument counter
 * @argv: the argument vector
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
       usage_error(); /* print usage_error */

	else
		exec(argv[1]); /* read the file and execute*/

	return (EXIT_SUCCESS);
}



/**
 * exec - function that reads the file and executes the monty byte
 *@argv: the file
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
				push_int_error(cmd.fd, cmd.buffer, stack, c_line); /** print push error*/
			else if (r == -1) /** get_op returns -1 if not the instruction */
				unknown_instruction_error(cmd.fd, cmd.buffer, stack, token, c_line);
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
	int i = 0, value = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
/*  	{"pint", pint},
		{"pop", pop},
        {"swap", swap},
        {"add", add},
		{"nop", nop},
		{"sub", sub},
        {"div", div},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"stack", stack},
        {"queue", queue}, */
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (isdigit(val) == 1)
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
 * _close - Frees all and closes files
 * @stack: Stack
 */
void _close(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		temp = *stack;
		*stack = (*stack)->next;

		free(temp);
	}
		fclose(cmd.fd);
		free(cmd.buffer);
}

/**
 * newnode - function that creates a new node
 * @n: value
 * Return: a new node
 */
stack_t *newnode(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
    malloc_error();
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
