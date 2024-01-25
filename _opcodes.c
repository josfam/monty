#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * is_legal - Checks whether the provided opcode is a legal opcode
 * @opcode: The opcode to check
 * Description: Checks whether the provided opcode is a legal opcode
 * Return: 1 if the opcode is legal, 0 otherwise.
 */
int is_legal(char *opcode)
{
	int i;
	char *legal_opcode;
	char *legal_opcodes[] = {
		"push", "pall", "pint", "pop", "swap",
		"add", "nop", "sub", "add", "mul", "div",
		"mod", "pchar", "pstr", "rotl", "rotr"
	};
	const int LEGAL_COUNT = sizeof(legal_opcodes) / sizeof(legal_opcodes[0]);

	for (i = 0; i < LEGAL_COUNT; i++)
	{
		legal_opcode = legal_opcodes[i];
		if (strcmp(opcode, legal_opcode) == 0)
			return (1);
	}

	return (0);
}

/**
 * is_lone - Checks whether the provided opcode is a lone opcode, i.e.
 *                  an opcode that shouldn't accept an argument.
 * @opcode: The opcode to check
 * Description: Checks whether the provided opcode is a lone opcode, i.e.
 *                  an opcode that shouldn't accept an argument.
 * Return: 1 if the opcode is a lone opcode, 0 otherwise.
 */
int is_lone(char *opcode)
{
	int i;
	char *lone_opcode;
	char *lone_opcodes[] = {
		"pall", "pint", "pop", "swap", "add",
		"nop", "sub", "add", "mul", "div",
		"mod", "pchar", "pstr", "rotl", "rotr"
	};
	const int LONE_COUNT = sizeof(lone_opcodes) / sizeof(lone_opcodes[0]);

	for (i = 0; i < LONE_COUNT; i++)
	{
		lone_opcode = lone_opcodes[i];
		if (strcmp(opcode, lone_opcode) == 0)
			return (1);
	}

	return (0);
}
