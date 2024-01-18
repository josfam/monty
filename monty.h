#ifndef MONTY_HEADER
#define MONTY_HEADER

#define MAX_LINE_LEN 100
#include <stdio.h>

extern int line_num;

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

/* Pushes an element to the stack */
void push(stack_t **tail, unsigned int value);

/* Checks if the stack is empty */
int is_empty(stack_t **tail);

/* Prints all the values on the stack, starting from the top of the stack */
void pall(stack_t **tail);

/* Frees the stack memory */
void free_stack(stack_t **tail);

/* Frees an array of strings */
void free_arr(char **arr);

/* Returns an array containing the monty instruction extracted */
/* from the provided string*/
char **extract_instruction(char *s);

/* Checks whether the provided opcode is a lone opcode, i.e. */
/*  an opcode that shouldn't accept an argument. */
int is_lone(char *opcode);

/* Checks whether the provided opcode is a legal opcode */
int is_legal(char *opcode);

/* Checks if the correct number of arguments were passed to main. */
/* Exits immediately if otherwise. */
void *check_args(int _argc);

/* Checks for a valid file, and returns it. Otherwise, exits the program. */
FILE *get_file(char **_argv);

/* Checks if the provided strings are equivalent */
int is_same(char *str1, char *str2);

/* Prints the value at the top of the stack, followed by a new line */
void pint(stack_t **tail);

#endif
