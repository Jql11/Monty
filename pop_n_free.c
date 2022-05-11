#include "monty.h"

/**
 * free_dlistint - frees a dlistint_t
 *@head: head
 * Return: void
 */
void free_dlistint(stack_t **head)
{
	stack_t *tmp;

	tmp = *head;
	while (*head != NULL)
	{
		*head = (*head)->next;
		free(tmp);
	}
}
/**
 * pop - deletes top node of doubly linked list
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(current);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(current);
	}
}
/**
 * nop - do nothing
 * @h: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void) h;
	(void) line_number;
}
