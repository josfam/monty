#include <stdio.h>
#include <string.h>
#include "../monty.h"

void print_command(char **command);

/**
* main - Entry point.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(void)
{
	int i, len;
	char *line;
	char **command;
	char *lines[] = {
		"  push 3",
		"                   pall    ",
		"      push    6        ",
		"                            ",
		"push 8"
	};

	len = 5;
	for (i = 0; i < len; i++)
	{
		line = lines[i];
		command = extract_command(line);
		print_command(command);
		if (command)
			free_arr(command);
	}

	return (0);
}

void print_command(char **command)
{
	int i;

	if (command == NULL)
	{
		printf("There was no command\n");
	}
	else
	{
		for (i = 0; command[i] != NULL; i++)
		{
			printf("%s", command[i]);
		}
		printf("\n");
	}
}
