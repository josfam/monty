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

/**
 * is_all_digits - Checks whether the string is composed of only digits
 * @s: The string to check
 * Description: Checks whether the string is composed of only digits
 * Return: 1 if the string is all digits, 0 otherwise
 */
int is_all_digits(char *s)
{
	int len, i;
	char ch;

	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		ch = s[i];
		/* sign is allowed at the start of the number */
		if (i == 0 && ch == '-' && len > 1)
		{
			;
		}
		else
		{
			if (!isdigit(s[i]))
				return (0);
		}
	}
	return (1);
}
