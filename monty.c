#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void exec_lone(stack_t **tail, char *opcode, char **command);
void exec_paired(stack_t **tail, char *arg, char *opcode, char **command,
				FILE *fp);

int line_num = 0;

/**
* main - Entry point.
* @argc: Length of array of command line arguments.
* @argv: Array of command line arguments.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(int argc, char *argv[])
{
	char **command;
	char *line, *opcode, *arg;
	char buffer[MAX_LINE_LEN];
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
		command = extract_command(line);
		if (!command)
			continue;

		opcode = command[0];
		arg = command[1];

		if (!(is_legal(opcode)))
		{
			fprintf(stderr, "L%d: unknown command %s\n", line_num, opcode);
			free_arr(command);
			fclose(fp);
			if (tail != NULL)
				free_stack(&tail);
			exit(EXIT_FAILURE);
		}
		else if (is_lone(opcode))
		{
			exec_lone(&tail, opcode, command);
		}
		else
		{
			exec_paired(&tail, arg, opcode, command, fp);
		}
	}
	if (tail != NULL)
		free_stack(&tail);
	fclose(fp);
	return (0);
}

/**
 * exec_lone - Executes an opcode that does not require and argument
 * @tail: The tail of the stack
 * @opcode: The opcode to execute
 * @command: Array of strings representing the full monty bytecode command
 * Description: Executes an opcode that does not require and argument
 * Return: Nothing
*/
void exec_lone(stack_t **tail, char *opcode, char **command)
{
	if (is_same("pall", opcode))
	{
		pall(tail);
		free_arr(command);
	}
	else if (is_same("pint", opcode))
	{
		pint(tail);
	}
	else if (is_same("nop", opcode))
	{
		;
	}
}

/**
 * exec_paired - Executes an opcode that requires an argument
 * @tail: The tail of the stack
 * @arg: The argument to the opcode
 * @opcode: The opcode to execute
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Executes an opcode that requires and argument
 * Return: Nothing
*/
void exec_paired(stack_t **tail, char *arg, char *opcode, char **command,
				FILE *fp)
{
	if (is_same("push", opcode))
	{
		if (!arg || !is_all_digits(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_arr(command);
			free_stack(tail);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		push(tail, atoi(arg));
		free_arr(command);
	}
}
