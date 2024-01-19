#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/* For classic stack-related functions */

/**
 * push - Pushes an element to the stack
 * @value: The integer element to push to the top of the stack
 * @tail: The tail of the stack onto which to push the element
 * Description: Pushes an element to the stack
 * Return: Nothing
 */
void push(stack_t **tail, unsigned int value)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	if (*tail == NULL) /* This is the first node */
		*tail = new;
	else
	{
		/* new node becomes the tail */
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Removes the element from the top of the stack
 * @tail: The tail of the stack from which to remove the element
 * @line_number: The line number being processed in the monty bytecode file
 * Description: Removes the element from the top of the stack
 * Return: The element that was popped
 */
void pop(stack_t **tail)
{
	stack_t *tmp;

	tmp = *tail;
	*tail = tmp->next;
	if (*tail != NULL)
		(*tail)->prev = NULL;
	free(tmp);
}
