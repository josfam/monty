#include <stdio.h>
#include <stddef.h>
#include "monty.h"

/* For functions that print out part or the whole of the linked list */

/**
 * pall - Prints all the values on the stack, starting from
 *        the top of the stack
 * @tail: The tail of the stack from which to remove the element
 * Description: Prints all the values on the stack, starting from
 *              the top of the stack
 * Return: Nothing
 */
void pall(stack_t **tail)
{
	stack_t *current;

	current = *tail;
	if (is_empty(&current)) /* don't print anything */
	{
		;
	}
	else
	{
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
}
