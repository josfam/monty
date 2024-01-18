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
	char **instruction;
	char *line, *opcode, *arg;
	char buffer[MAX_LINE_LEN];
	int line_num;
	FILE *fp;
	stack_t *tail;

	check_args(argc);
	fp = get_file(argv);

	tail = NULL;

	/* read lines from the monty byte file */
	while (1)
	{
		line = fgets(buffer, sizeof(buffer), fp);
		if (!line)
			break;

		line_num++;
		instruction = extract_instruction(line);
		opcode = instruction[0];
		arg = instruction[1];

		if (!opcode) /* there was no instruction */
			continue;
		else if (!(is_legal(opcode)))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			exit(EXIT_FAILURE);
		}
		else if (is_lone(opcode))
		{
			/* TODO */
		}
		else
		{
			/* TODO */
		}
	}

	fclose(fp);
	return (0);
}
