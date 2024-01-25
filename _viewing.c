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
			fprintf(stdout, "%d\n", current->n);
			current = current->prev;
		}
	}
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @tail: The tail of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: prints the value at the top of the stack,
 *              followed by a new line
 * Return: Nothing
 */
void pint(stack_t **tail, char **command, FILE *fp)
{
	if (is_empty(tail))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_and_exit(tail, command, fp);
	}
	fprintf(stdout, "%d\n", (*tail)->n);
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @tail: The tail of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Prints the char at the top of the stack, followed by a new line
 * Return: Nothing
 */
void pchar(stack_t **tail, char **command, FILE *fp)
{
	int value;

	if (is_empty(tail))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_and_exit(tail, command, fp);
	}
	value = (*tail)->n;
	if (!(value >= 0 && value <= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_and_exit(tail, command, fp);
	}

	printf("%c\n", value);
}

/**
 * pstr - Prints the char at the top of the stack, followed by a new line
 * @tail: The tail of the stack
 * Description: Prints the char at the top of the stack, followed by a new line
 * Return: Nothing
 */
void pstr(stack_t **tail)
{
	int value;
	stack_t *current;

	if (*tail == NULL)
		;
	else
	{
		current = *tail;
		while (current != NULL)
		{
			value = current->n;
			/* stop printing if a 0 or non-ascii character is encountered */
			if (value == 0 || !(value >= 0 && value <= 127))
				break;
			printf("%c", value);
			current = current->prev;
		}
		printf("\n");
	}
}
