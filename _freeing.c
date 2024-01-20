#include <stdlib.h>
#include "monty.h"

/* For functions related to freeing memory */

/**
 * free_stack - Frees the stack memory
 * @tail: The tail of the stack to free
 * Description: Frees the stack memory
 * Return: Nothing
 */
void free_stack(stack_t **tail)
{
	stack_t *current;

	if (*tail == NULL) /* Do nothing */
	{
		;
	}
	else
	{
		current = *tail;
		while (current->prev != NULL)
		{
			current = current->prev;
			free(*tail);
			*tail = current;
		}
		free(current);
	}
}

/**
 * free_arr - Frees an array of strings
 * @arr: The array to free
 * Description - Frees an array of strings
 * Return: Nothing
 */
void free_arr(char **arr)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		if (arr[i] != NULL)
			free(arr[i]);
	}

	free(arr);
}

/**
 * free_and_exit - Frees memory and exits the program
 * @tail: The tail of the stack
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Frees memory and exits the program
 * Return: Nothing
*/
void free_and_exit(stack_t **tail, char **command, FILE *fp)
{
	free_arr(command);
	free_stack(tail);
	fclose(fp);
	exit(EXIT_FAILURE);
}
