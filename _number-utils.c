#include "monty.h"

/* For general purpose operations involving numbers */

/**
 * is_all_digits - Checks whether the string is composed of only digits
 * @s: The string to check
 * Description: Checks whether the string is composed of only digits
 * Return: 1 if the string is all digits, 0 otherwise
 */
int is_all_digits(char *s)
{
	int len, i;
	char ch;

	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		ch = s[i];
		/* sign is allowed at the start of the number */
		if (i == 0 && ch == '-' && len > 1)
		{
			;
		}
		else
		{
			if (!isdigit(s[i]))
				return (0);
		}
	}
	return (1);
}
