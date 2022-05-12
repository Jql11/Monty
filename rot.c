#include "monty.h"

/**
 * rotl - rotate stack to top
 * @stack: the stack to rotate
 * @line_number: line number in monty, not used
 *
 * Description: top element becomes last
 * second element becomes top
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int value = (*stack)->n;
	(void)line_number;

	if (*stack == NULL || stack == NULL || *stack->next == NULL)
		return;

	while (temp->next != NULL)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = value;
}

/**
 * rotr - rotate stack to bottom
 * @stack: the stack to rotate
 * @line_number: line number in monty, not used
 *
 * Description: last element becomes first
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int value = (*stack)->n;
	(void)line_number;

	if (*stack == NULL || stack == NULL || *stack->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	while (temp->prev != NULL)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = value;
}
