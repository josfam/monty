#include <string.h>
#include "monty.h"

/**
 * is_same - Checks if the provided strings are equivalent
 * @str1: The first string
 * @str2: The second string
 * Description: Checks if the provided strings are equivalent
 * Return: 1 if the provided strings are equivalent, 0 if they are not
*/
int is_same(char *str1, char *str2)
{
	if (strcmp(str1, str2) == 0)
		return (1);
	return (0);
}
