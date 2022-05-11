#include "monty.h"
/**
  * pchar - prints the char at top of the stack
  * @stack: stack
  * @line_number: line number
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
  *pstr - prints the string srtarting at the top of the stack, followed by newline
  * @stack: stack
  * @line_number: line number
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!stack)
		return;
	if (!*stack)
		printf("\n");
	while (*stack != NULL && (*stack)->n != 0)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c", (*stack)->n);
		else
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		*stack = (*stack)->next;
	}
	printf("\n");
}
