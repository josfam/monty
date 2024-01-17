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

	return (0);
}
