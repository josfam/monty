#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/* For math-related functions */

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

/**
 * mul - Multiplies the second top element of the stack with the top element
 *       of the stack
 * @tail: The entry point of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Multiplies the second top element of the stack with the
 *              top element of the stack
 * Return: Nothing
 */
void mul(stack_t **tail, char **command, FILE *fp)
{
	int result;
	stack_t *previous;

	if (stack_size(tail) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_and_exit(tail, command, fp);
	}
	previous = (*tail)->prev;

	/* store multiplication in second top element, and pop the tail */
	result = previous->n * (*tail)->n;
	previous->n = result;
	pop(tail, command, fp);
}

/**
 * divide - Divides the second top element of the stack by the top element
 *       of the stack
 * @tail: The entry point of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Divides the second top element of the stack by the top element
 *              of the stack
 * Return: Nothing
 */
void divide(stack_t **tail, char **command, FILE *fp)
{
	int result;
	stack_t *previous;

	if (stack_size(tail) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_and_exit(tail, command, fp);
	}

	if ((*tail)->n == 0) /* avoid dividing by zero */
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_and_exit(tail, command, fp);
	}

	previous = (*tail)->prev;

	/* store division in the second top element, and pop the tail */
	result = previous->n / (*tail)->n;
	previous->n = result;
	pop(tail, command, fp);
}
