#include <stdio.h>
#include <string.h>
#include "../monty.h"

void print_instruction(char **instruction);

/**
* main - Entry point.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(void)
{
	int i, len;
	char *line;
	char **instruction;
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
		instruction = extract_instruction(line);
		print_instruction(instruction);
	}

	return (0);
}

void print_instruction(char **instruction)
{
	if (instruction == NULL)
	{
		printf("instruction is NULL\n");
	}
	else
	{
		while(*instruction != NULL)
		{
			printf("%s", *instruction);
			instruction++;
		}
		printf("\n");
	}
}
