# C - Stacks, Queues - LIFO, FIFO

![img](https://res.cloudinary.com/practicaldev/image/fetch/s--XWnztdhd--/c_imagga_scale,f_auto,fl_progressive,h_900,q_auto,w_1600/https://cl.ly/d84e17fec485/Image%25202018-09-13%2520at%252012.22.09%2520PM.png)

## Description
This is a group project during the first year of Holberton School. Stacks and queues in C are data structures that can be implemented using either arrays or linked lists.

## Resources
### Read or Watch:
- [Google](https://www.google.com/webhp?q=stack%20and%20queue)
- [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
- [Piles et Files](https://www.youtube.com/watch?v=v_g1yizlUxc)
- [Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)

## Requirements
- > All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic`
- > You allowed to use a maximum of one global variable
- > No more than 5 functions per file
- > You are allowed to use the C standard library
- > You are expected to do the tasks in the order shown in the project

--------------------------------------------
## More Info
### Data structures
Please use the following data structures for this project. Don’t forget to include them in your header file.
```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;
```
```c
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

### Compilation & Output

- Your code will be compiled this way:

	$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

- Any output must be printed on `stdout`
- Any error message must be printed on `stderr`
 - [Here is a link to a GitHub repository](https://github.com/sickill/stderred) that could help you making sure your errors are printed on stderr

### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files
Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

	julien@ubuntu:~/monty$ cat -e bytecodes/000.m
	push 0$
	push 1$
	push 2$
	push 3$
					pall    $
	push 4$
		push 5    $
		push    6        $
	pall$
	julien@ubuntu:~/monty$

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

	julien@ubuntu:~/monty$ cat -e bytecodes/001.m
	push 0 Push 0 onto the stack$
	push 1 Push 1 onto the stack$
	$
	push 2$
	push 3$
					pall    $
	$
	$
							$
	push 4$
	$
		push 5    $
		push    6        $
	$
	pall This is the end of our program. Monty is awesome!$
	julien@ubuntu:~/monty$

#### The monty program

- Usage: `monty file`
 - where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
 - where `<file>` is the name of the file
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
 - where is the line number where the instruction appears.
 - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
 - it executed properly every line of the file
 - it finds an error in the file
 - an error occured
- If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
- You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

--------------------------------------------
## Tasks
### 0. push, pall
Implement the `push` and `pall` opcodes.

#### The push opcode
The opcode push pushes an element to the stack.

- Usage: `push <int>`
 - where `<int>` is an integer
- if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
 - where is the line number in the file
- You won’t have to deal with overflows. Use the `atoi` function

#### The pall opcode
The opcode `pall` prints all the values on the stack, starting from the top of the stack.
- Usage `pall`
- Format: see example
- If the stack is empty, don’t print anything

```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

--------------------------------------------
### 1. pint
Implement the `pint` opcode.

#### The pint opcode
The opcode pint prints the value at the top of the stack, followed by a new line.

- Usage: `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$
```

--------------------------------------------
### 2. pop
Implement the `pop` opcode.

#### The pop opcode
The opcode `pop` removes the top element of the stack.

- Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```

--------------------------------------------
### 3. swap
Implement the `swap` opcode.

#### The swap opcode
The opcode `swap` swaps the top two elements of the stack.

- Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```

--------------------------------------------
### 4. add
Implement the `add` opcode.

#### The add opcode
The opcode `add` adds the top two elements of the stack.

- Usage: `add`
- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
 - The top element of the stack contains the result
 - The stack is one element shorter

```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```

--------------------------------------------
### 5. nop
Implement the `nop` opcode.

#### The nop opcode
The opcode `nop` doesn’t do anything.
- Usage: `nop`
