#include "monty.h"
#define LIMIT 100 /* Specifying the maximum limit of the stack */

/**
 * main - the main function of the Monty Project
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: The success or error.
 */


int main(int argc, char *argv[])
{
	FILE *monty_file;

	instruction_t op_functions[] = {
		{"push", op_push},
/*      {"pall", op_pall},
		{"pint", op_pint},
        {"pop", op_pop},
		{"swap", op_swap},
        {"add", op_add},
        {"nop", op_nop},
		{"sub", op_sub},
        {"div", op_div},
		{"mul", op_mul},
        {"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
        {"rotl", op_rotl},
		{"rotr", op_rotr},
        {"stack", op_stack},
		{"queue", op_queue},  */
        {NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");

	if (!monty_file)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	exec(monty_file, op_functions);

	fclose(monty_file);

	return (0);
}
