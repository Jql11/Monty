#include "monty.h"

/**
 * free_dlistint - frees a double linked list
 * @stack: stack to free
 * Return: void
 */
void free_dlistint(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack != NULL)
	{
		tmp = stack;
		stack = (stack)->next;
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
	stack_t *current = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if ((*stack)->next == NULL)
	{
		free(current);
		*stack = NULL;
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
 * @stack: stack
 * @line_number: bytecode line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
  *swap - swap locations of previous stack with the top stack
 * @stack: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next != NULL)
		(*stack)->next->prev = *stack;
	tmp->next = *stack;
	*stack = tmp;
}
