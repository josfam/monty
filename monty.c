#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void exec_lone_opcode(stack_t **tail, char *opcode);
void exec_paired_opcode(stack_t **tail, char *arg, char *opcode);

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
	char **instruction;
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
		instruction = extract_instruction(line);
		opcode = instruction[0];
		arg = instruction[1];

		if (!opcode) /* there was no instruction */
		{
			continue;
		}
		else if (!(is_legal(opcode)))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			exit(EXIT_FAILURE);
		}
		else if (is_lone(opcode))
		{
			exec_lone_opcode(&tail, opcode);
		}
		else
		{
			exec_paired_opcode(&tail, arg, opcode);
		}
	}

	fclose(fp);
	return (0);
}

/**
 * exec_lone_opcode - Executes an opcode that does not require and argument
 * @tail: The tail of the stack
 * @opcode: The opcode to execute
 * Description: Executes an opcode that does not require and argument
 * Return: Nothing
*/
void exec_lone_opcode(stack_t **tail, char *opcode)
{
	if (is_same("pall", opcode))
	{
		pall(tail);
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
 * exec_paired_opcode - Executes an opcode that requires an argument
 * @tail: The tail of the stack
 * @arg: The argument to the opcode
 * @opcode: The opcode to execute
 * Description: Executes an opcode that requires and argument
 * Return: Nothing
*/
void exec_paired_opcode(stack_t **tail, char *arg, char *opcode)
{
	if (is_same("push", opcode))
	{
		if (!arg || (atoi(arg) == 0 && !is_same("0", arg)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		push(tail, atoi(arg));
	}
}
