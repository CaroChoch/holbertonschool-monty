#include "monty.h"

stack_t **global_var;

/**
 * main - the main function of the monty program
 * @argc: the argument counter
 * @argv: the argument vector
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	global_var = &head;

	exec(argv[1], &head);

	atexit(_free);
	exit(EXIT_SUCCESS);
}


/**
 * exec - function that reads the file and executes the monty byte
 * @file: the name of the file
 * @stack: pointer to the top of the stack
 */
void exec(char *file, stack_t **stack)
{
	size_t size;
	ssize_t read_line;
	unsigned int num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	fd = fopen(file, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &size, fd)) != -1)
	{
		command = strtok(line, DELIMS);
		num++;

		if (command)
			get_op(stack, command, num);
	}

	if (line)
		free(line);

	fclose(fd);
}

/**
 * get_op - function that get the operation function
 * @stack: stack or queue
 * @op: line with commands and instructions
 * @line_number: line number
 */
void get_op(stack_t **stack, char *op, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{NULL, NULL} /* to be completed */
	};

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}

	if (strlen(op) != 0 && op[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
