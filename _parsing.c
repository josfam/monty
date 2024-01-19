#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/* For parsing-related functions */

/**
 * extract_command - Returns an array containing the monty command
 *                       extracted from the provided string
 * @s: The string to extract the command from
 * Description: Returns an array containing the monty command extracted
 *              from the provided string
 * Return: An array of strings, consisting of the command extracted
*/
char **extract_command(char *s)
{
	char *delim = " \t\n";
	char *tallying, *token, *filling;
	char **command;
	int token_count, i;
	const int MAX_command_LEN = 2;

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

	if (token_count == 0)  /* There was no command */
	{
		free(filling);
		return (NULL);
	}

	/* 3-element array to hold an opcode, an opcode and argument, or nothing */
	command = malloc(sizeof(char *) * (MAX_command_LEN + 1));
	for (i = 0; i < MAX_command_LEN + 1; i++)
		command[i] = NULL;

	/* there is 1 opcode, or 1 opcode and and 1 argument*/
	token = strtok(filling, delim);
	for (i = 0; i < token_count; i++)
	{
		command[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	free(filling);

	return (command);
}
