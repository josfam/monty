#include <stdlib.h>
#include "monty.h"

/* For functions related to freeing memory */

/**
 * free_stack - Frees the stack memory
 * @tail: The tail of the stack to free
 * Description: Frees the stack memory
 * Return: Nothing
 */
void free_stack(stack_t **tail)
{
	stack_t *current;

	current = *tail;
	while (current->prev != NULL)
	{
		current = current->prev;
		free(*tail);
		*tail = current;
	}
	free(current);
}
