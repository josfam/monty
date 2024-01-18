#include <stdio.h>
#include "../monty.h"

int main(void)
{
	stack_t *tail;

	tail = NULL;
	push(&tail, 0);
	push(&tail, 1);
	push(&tail, 2);
	push(&tail, 3);
	pall(&tail);
	push(&tail, 4);
	push(&tail, 5);
	push(&tail, 6);
	pall(&tail);

	free_stack(&tail);
	return (0);
}
