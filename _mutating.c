#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @tail: The tail of the stack onto which to push the element
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Swaps the top two elements of the stack
 * Return: Nothing
 */
void swap(stack_t **tail, char **command, FILE *fp)
{
	stack_t *previous;
	int temp;

	if (stack_size(tail) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_and_exit(tail, command, fp);
	}

	previous = (*tail)->prev;

	/* swap values */
	temp = (*tail)->n;
	(*tail)->n = previous->n;
	previous->n = temp;
}
