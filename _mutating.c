#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/* Non-math related functions that mutate the behaviour of the linked list */

/**
 * swap - Swaps the top two elements of the stack
 * @tail: The entry point of the stack
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

/**
 * rotl - Rotates the stack to the top
 * @tail: The entry point of the stack
 * Description: Rotates the stack to the top
 * Return: Nothing
 */
void rotl(stack_t **tail)
{
	stack_t *current, *new_head, *prev;

	current = *tail;
	if (is_empty(tail) || stack_size(tail) == 1) /* Do nothing */
	{
		;
	}
	else
	{
		new_head = malloc(sizeof(stack_t));
		new_head->n = (*tail)->n;
		new_head->prev = NULL;
		while (current->prev != NULL) /* reach the head of the stack */
		{
			current = current->prev;
		}
		new_head->next = current;
		current->prev = new_head;

		/* pop the tail */
		prev = (*tail)->prev;
		free(*tail);
		*tail = prev;
	}
}
