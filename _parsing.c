#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * extract_instruction - Returns an array containing the monty instruction
 *                       extracted from the provided string
 * @s: The string to extract the instruction from
 * Description: Returns an array containing the monty instruction extracted
 *              from the provided string
 * Return: An array of strings, consisting of the instruction extracted
*/
char **extract_instruction(char *s)
{
	char *delim = " ";
	char *tallying, *token, *filling;
	char **instruction;
	int token_count, i;
	const int MAX_INSTRUCTION_LEN = 2;

	tallying = strdup(s);
	filling = strdup(s);
	token_count = 0;

	token = strtok(tallying, delim);
	while (token != NULL)
	{
		token_count++;
		if (strcmp(token, "pall") == 0) /* pall can only exist on its own */
			break;
		if (token_count == MAX_INSTRUCTION_LEN) /* stop getting tokens */
			break;
		token = strtok(NULL, delim);
	}
	free(tallying);

	if (token_count == 0)  /* There was no instruction */
		return (NULL);

	instruction = malloc(sizeof(char *) * (token_count + 1));

	/* populate instruction array */
	token = strtok(filling, delim);
	for (i = 0; i < token_count; i++)
	{
		instruction[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	free(filling);
	instruction[i] = NULL;

	return (instruction);
}
