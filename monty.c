#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void exec_lone(stack_t **tail, char *opcode, char **command);
void exec_paired(stack_t **tail, char *arg, char *opcode, char **command);

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
			exit(EXIT_FAILURE);
		}
		else if (is_lone(opcode))
		{
			exec_lone(&tail, opcode, command);
		}
		else
		{
			exec_paired(&tail, arg, opcode, command);
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
 * Description: Executes an opcode that requires and argument
 * Return: Nothing
*/
void exec_paired(stack_t **tail, char *arg, char *opcode, char **command)
{
	if (is_same("push", opcode))
	{
		if (!arg || (atoi(arg) == 0 && !is_same("0", arg)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_arr(command);
			exit(EXIT_FAILURE);
		}
		push(tail, atoi(arg));
		free_arr(command);
	}
}
