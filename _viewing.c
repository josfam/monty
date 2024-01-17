#include <stdio.h>
#include <stddef.h>
#include "monty.h"

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

/**
 * is_empty - Checks if the stack is empty
 * @tail: The tail of the stack
 * Description: Checks if the stack is empty
 * Return: 1 if the stack is empty, 0 otherwise
 */
int is_empty(stack_t **tail)
{
	if (tail == NULL)
		return (1);
	return (0);
}
