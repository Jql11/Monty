#include "main.h"

void push(stack_t **stack, unsigned int line_number);

/**
 * pall - print all values on the stack
 * @stack: the stack to print
 * @line_number: unused attribute
 *
 * Description: simple loop using a temp pointer to print
 * all values on the stack
 *
 * Return: void return
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
