#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

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
 * sub - subtracts the top element of the stack from the second top element
 *       of the stack
 * @tail: The entry point of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: subtracts the top element of the stack from the second
 *              top element of the stack
 * Return: Nothing
 */
void sub(stack_t **tail, char **command, FILE *fp)
{
	int result;
	stack_t *previous;

	if (stack_size(tail) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_and_exit(tail, command, fp);
	}

	previous = (*tail)->prev;

	/* store difference in second top element, and pop the tail */
	result = previous->n - (*tail)->n;
	previous->n = result;
	pop(tail, command, fp);
}

/**
 * add - Adds the top two elements of the stack
 * @tail: The entry point of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Adds the top two elements of the stack
 * Return: Nothing
 */
void add(stack_t **tail, char **command, FILE *fp)
{
	int result;
	stack_t *previous;

	if (stack_size(tail) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_and_exit(tail, command, fp);
	}

	previous = (*tail)->prev;

	/* store sum in second top element, and pop the tail */
	result = previous->n + (*tail)->n;
	previous->n = result;
	pop(tail, command, fp);
}
