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

/**
 * pint - print value of top stack
 * @stack: the stack to assess
 * @line_number: line number
 *
 * Description: print value of top stack
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number);
{
	stack *temp = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
