#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
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
	if (*tail == NULL)
	{
		return (1);
	}
	return (0);
}
