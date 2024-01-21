#include <stdio.h>
#include <stdlib.h>

/**
 * check_args - Checks if the correct number of arguments were passed to main,
 *              and checks if a valid file was passed into main.
 *              If so, a pointer to the file is returned.
 *              Otherwise, the program exits in both cases.
 * @_argc: The argument count passed into main
 * @_argv: The argument vector passed into main
 * Description: Checks if the correct number of arguments were passed to main,
 *              and checks if a valid file was passed into main.
 *              If so, a pointer to the file is returned.
 *              Otherwise, the program exits in both cases.
 * Return: Nothing
*/
FILE *check_args(int _argc, char **_argv)
{
	char *monty_file;
	FILE *fp;

	if (!(_argc == 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = _argv[1];
	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
