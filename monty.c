#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* main - Entry point.
* @argc: Length of array of command line arguments.
* @argv: Array of command line arguments.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(int argc, char *argv[])
{
	char *monty_file;
	FILE *fp;

	if (!(argc == 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = argv[1];
	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}

	fclose(fp);
	return (0);
}
