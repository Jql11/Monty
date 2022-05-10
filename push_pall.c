#include "main.h"

/**
 * push - push an element to the stack
 * @stack: stack to add to
 * @line_number: line number in monty file
 * @n: value of new node
 *
 */

void push(stack_t **stack, unsigned int line_number, int n);
{
	stack_t *new_node;

	if ((*stack) == NULL)
	{
		fprintf("L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	 /* create new node and allocate memory */
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = n; /*give it a value*/
	new_node->next = *stack; /*point next to old head */
	new_node->prev = NULL; /*point prev to NULL to indicate new head*/

	if ((*stack) != NULL) /*point old head node prev to new node */
		(*stack)->prev = new_node;
	*stack = new_node; /*point head to new node */

}

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
