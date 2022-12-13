#ifndef _MONTY_H_
#define _MONTY_H_
#define LIMITERS " \t\n"

/* --------------- Extern Libraries ----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* ---------------- Prototypes ------------------ */
int main(int argc, char *argv[]);
void op_push(stack_t **stack, unsigned int line_number);
void token_error(stack_t *stack, unsigned int number, FILE *file, char *tok);
void frees(stack_t *stack);
void exec(FILE *monty_file, instruction_t instructions[]);
void is_number(stack_t *stack, unsigned int lnumber, char *token, FILE *mfile);

int n;


#endif
