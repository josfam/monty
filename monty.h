#ifndef MONTY_HEADER
#define MONTY_HEADER

#define MAX_LINE_LEN 100
#include <stdio.h>

extern int line_number;
#define DELIMS " \n\t"

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
void push(stack_t **tail, char *value, char **command, FILE *fp);

/* Pops the top element of the stack */
void pop(stack_t **tail, char **command, FILE *fp);

/* Returns the size of the stack */
int stack_size (stack_t **tail);

/* Checks if the stack is empty */
int is_empty(stack_t **tail);

/* Prints all the values on the stack, starting from the top of the stack */
void pall(stack_t **tail);

/* Frees the stack memory */
void free_stack(stack_t **tail);

/* Frees an array of strings */
void free_arr(char **arr);

/* Frees memory and exits the program */
void free_and_exit(stack_t **tail, char **command, FILE *fp);

/* Returns an array containing the monty command extracted */
/* from the provided string*/
char **extract_command(char *s);

/* Checks whether the provided opcode is a lone opcode, i.e. */
/*  an opcode that shouldn't accept an argument. */
int is_lone(char *opcode);

/* Checks whether the provided opcode is a legal opcode */
int is_legal(char *opcode);

/* Checks if the correct number of arguments were passed to main, and if a */
/* valid file was provided. A pointer to the file is returned if so */
/* Exits immediately otherwise. */
FILE *check_args(int _argc, char **_argv);

/* Checks if the provided strings are equivalent */
int is_same(char *str1, char *str2);

/* Prints the value at the top of the stack, followed by a new line */
void pint(stack_t **tail, char **command, FILE *fp);

/* Swaps the top two elements of the stack */
void swap(stack_t **tail, char **command, FILE *fp);

/* subtracts the top element of the stack from the second top element */
/* of the stack */
void sub(stack_t **tail, char **command, FILE *fp);

/* Adds the top two elements of the stack */
void add(stack_t **tail, char **command, FILE *fp);

/* Multiplies the second top element of the stack with the top element */
/* of the stack */
void mul(stack_t **tail, char **command, FILE *fp);

/*  Divides the second top element of the stack by the top element */
/* of the stack*/
void divide(stack_t **tail, char **command, FILE *fp);

/* Computes the rest of the division of the second top element of the stack */
/* by the top element of the stack. */
void mod(stack_t **tail, char **command, FILE *fp);

/* nop - Does nothing */
void nop();

/* Checks whether the string is composed of only digits */
int is_all_digits(char *s);

#endif
