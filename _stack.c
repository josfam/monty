#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/* For classic stack-related functions */

int line_number = 0;

/**
 * push - Pushes an element to the stack
 * @tail: The tail of the stack onto which to push the element
 * @value: The integer element to push to the top of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Pushes an element to the stack
 * Return: Nothing
 */
void push(stack_t **tail, char *value, char **command, FILE *fp)
{
	stack_t *new;

	if (!value || !is_all_digits(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_and_exit(tail, command, fp);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(value);
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
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Removes the element from the top of the stack
 * Return: The element that was popped
 */
void pop(stack_t **tail, char **command, FILE *fp)
{
	stack_t *tmp;

	if (tail == NULL || *tail == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_and_exit(tail, command,  fp);
	}

	tmp = *tail;
	*tail = tmp->prev;
	if (*tail != NULL)
		(*tail)->next = NULL;
	free(tmp);
}

/**
 * size - Returns the size of the stack
 * @tail: The tail of the stack whose size to get
 * Description: Returns the size of the stack
 * Return: The size of the stack
 */
int stack_size (stack_t **tail)
{
	int size;
	stack_t *current;

	size = 0;
	if (*tail == NULL) /* empty */
		return (0);

	current = *tail;
	while (current != NULL)
	{
		size++;
		current = current->prev;
	}

	return (size);
}
