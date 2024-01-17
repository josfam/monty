#ifndef MONTY_HEADER
#define MONTY_HEADER

#define MAX_LINE_LEN 100

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

/* Removes the element from the top of the stack */
int pop(stack_t **tail, unsigned int line_number);

/* Swaps the top two elements of the stack */
void swap(stack_t **tail, unsigned int line_number);

#endif
