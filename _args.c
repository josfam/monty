#include <stdio.h>
#include <stdlib.h>

/**
 * check_args - Checks if the correct number of arguments were passed to main
 * @_argc: The argument count
 * Description: Checks if the correct number of arguments were passed to main.
 *              Exits immediately if otherwise.
 * Return: Nothing
*/
void check_args(int _argc)
{
	if (!(_argc == 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		;
	}
}

/**
 * get_file - Checks for a valid file, and returns it. Otherwise, exits the
 *            program.
 * @_argv: The argument vector passed into main
 * Description: Checks for a valid file, and returns it. Otherwise, exits the
 *            program.
 * Return: A pointer to a file stream if the file is valid. Exits the program
 *         otherwise.
*/
FILE *get_file(char **_argv)
{
	char *monty_file;
	FILE *fp;

	monty_file = _argv[1];
	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
