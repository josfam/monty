#include <stdio.h>
#include <stddef.h>
#include "../monty.h"

/**
* main - Entry point.
* Description: The main entry point of the program.
* Return: 0 if successful, Non-zero otherwise.
*/
int main(void)
{
	stack_t *stack;

	printf("size: %d\n", stack_size(&stack));
	push(&stack, "0", NULL, NULL);
	push(&stack, "0", NULL, NULL);
	push(&stack, "0", NULL, NULL);
	printf("size: %d\n", stack_size(&stack));
	pop(&stack, NULL, NULL);
	pop(&stack, NULL, NULL);
	printf("size: %d\n", stack_size(&stack));
	pop(&stack, NULL, NULL);
	pop(&stack, NULL, NULL);
    return (0);
}

