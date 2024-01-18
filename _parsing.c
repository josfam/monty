#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/* For parsing-related functions */

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
	char *delim = " \t\n";
	char *tallying, *token, *filling;
	char **instruction;
	int token_count, i;
	const int MAX_INSTRUCTION_LEN = 2;

	tallying = strdup(s);
	filling = strdup(s);
	token_count = 0;

	/* count how many tokens there are in the string */
	token = strtok(tallying, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	free(tallying);

	/* 3-element array to hold an opcode, an opcode and argument, or nothing */
	instruction = malloc(sizeof(char *) * (MAX_INSTRUCTION_LEN + 1));
	for (i = 0; i < MAX_INSTRUCTION_LEN + 1; i++)
		instruction[i] = NULL;

	if (token_count == 0)  /* There was no instruction */
		return (instruction);

	/* there is 1 opcode, or 1 opcode and and 1 argument*/
	token = strtok(filling, delim);
	for (i = 0; i < token_count; i++)
	{
		instruction[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	free(filling);

	return (instruction);
}
