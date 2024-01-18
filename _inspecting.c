#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

/* For inspection functions that do not mutate or view the linked list */

/**
 * is_empty - Checks if the stack is empty
 * @tail: The tail of the stack
 * Description: Checks if the stack is empty
 * Return: 1 if the stack is empty, 0 otherwise
 */
int is_empty(stack_t **tail)
{
	if (tail == NULL)
	{
		return (1);
	}
	return (0);
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @tail: The tail of the stack
 * Description: prints the value at the top of the stack,
 *              followed by a new line
 * Return: Nothing
 */
void pint(stack_t **tail)
{
	if (is_empty(tail))
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*tail)->n);
}
