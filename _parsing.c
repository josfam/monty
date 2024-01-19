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
	char *tallying, *token, *filling;
	char **command;
	int token_count, i;
	const int MAX_COMMAND_LEN = 2;

	tallying = strdup(s);
	filling = strdup(s);
	token_count = 0;

	token = strtok(tallying, DELIMS); /* count how many tokens there are */
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, DELIMS);
	}
	free(tallying);

	if (token_count == 0)  /* There was no command */
	{
		free(filling);
		return (NULL);
	}

	/* 3-element array to hold an opcode, an opcode and argument, or nothing */
	command = malloc(sizeof(char *) * (MAX_COMMAND_LEN + 1));
	for (i = 0; i < MAX_COMMAND_LEN + 1; i++)
		command[i] = NULL;

	/* clip token count to count 1 opcode, or 1 opcode and and 1 argument */
	if (token_count > MAX_COMMAND_LEN)
		token_count = MAX_COMMAND_LEN;
	token = strtok(filling, DELIMS);
	for (i = 0; i < token_count; i++)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIMS);
	}
	free(filling);

	return (command);
}
