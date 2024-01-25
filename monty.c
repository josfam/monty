#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void exec_lone(stack_t **tail, char *opcode, char **command, FILE *fp);
void exec_paired(stack_t **tail, char *arg, char *opcode, char **command,
				FILE *fp);

/**
* main - Entry point.
* @argc: Length of array of command line arguments.
* @argv: Array of command line arguments.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(int argc, char *argv[])
{
	char **command, *line, *opcode, *arg, buffer[MAX_LINE_LEN];
	FILE *fp;
	stack_t *tail;

	fp = check_args(argc, argv);
	tail = NULL;
	command = NULL;

	while (1) /* read and interpret lines from the monty byte file */
	{
		line = fgets(buffer, sizeof(buffer), fp);
		if (!line)
			break;

		line_number++;
		command = extract_command(line);
		if (!command)
			continue;

		opcode = command[0];
		arg = command[1];
		if (opcode[0] == '#') /* do nothing for a comment */
		{
			nop();
			free_arr(command);
		}
		else if (!(is_legal(opcode)))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_and_exit(&tail, command, fp);
		}
		else if (is_lone(opcode))
			exec_lone(&tail, opcode, command, fp);
		else
			exec_paired(&tail, arg, opcode, command, fp);
	}
	free_stack(&tail);
	fclose(fp);
	return (0);
}

/**
 * exec_lone - Executes an opcode that does not require and argument
 * @tail: The tail of the stack
 * @opcode: The opcode to execute
 * @command: Array of strings representing the full monty bytecode command
 * @fp: A pointer to the open monty bytecode file
 * Description: Executes an opcode that does not require and argument
 * Return: Nothing
*/
void exec_lone(stack_t **tail, char *opcode, char **command, FILE *fp)
{
	if (is_same("pall", opcode))
		pall(tail);
	if (is_same("pint", opcode))
		pint(tail, command, fp);
	if (is_same("pop", opcode))
		pop(tail, command, fp);
	if (is_same("swap", opcode))
		swap(tail, command, fp);
	if (is_same("sub", opcode))
		sub(tail, command, fp);
	if (is_same("add", opcode))
		add(tail, command, fp);
	if (is_same("mul", opcode))
		mul(tail, command, fp);
	if (is_same("div", opcode))
		divide(tail, command, fp);
	if (is_same("mod", opcode))
		mod(tail, command, fp);
	if (is_same("pchar", opcode))
		pchar(tail, command, fp);
	if (is_same("pstr", opcode))
		pstr(tail);
	if (is_same("rotl", opcode))
		rotl(tail);
	if (is_same("rotr", opcode))
		rotl(tail);
	if (is_same("nop", opcode)) /* do nothing */
		nop();
	free_arr(command);
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
		push(tail, arg, command, fp);

	free_arr(command);
}
