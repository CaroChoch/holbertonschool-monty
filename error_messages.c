#include "monty.h"


/**
 * usage_error - function that prints an usage error message
 * Return: always EXIT_FAILURE
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - function that prints an open file error message
 *@file: file name
 * Return: always EXIT_FAILURE
 */
void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file), exit(EXIT_FAILURE);
}

/**
 * unk_err - function that prints unknown instruction error message
 * @fd: is a file descriptor
 * @buffer: is a buffer
 * @stack: is a stack or queue
 * @line_cmd: is a line command in Monty bytecodes file where error occured
 * @val: number
 */
void unk_err(FILE *fd, char *buffer, stack_t *stack, int line_cmd)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_cmd);
	fclose(fd);
	free(buffer);
	_free(stack);
	exit(EXIT_FAILURE);
}


/**
 * push_int_error - function that prints invalid monty_push argument error
 *			messages
 * @fd: is a file desciptor
 * @buffer: is a buffer
 * @stack: is a stack or queue
 * @line_number: Line number in Monty bytecodes file where error occurred
 */
void push_int_error(FILE *fd, char *buffer, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(buffer);
	_free(stack);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

