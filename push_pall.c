#include "monty.h"

/**
  *is_integer - check if int is integer
  *@n: number
  *return: 0 on success
  */

int is_integer(const char *n)
{
	int i = 0;

	if (n[0] == '-')
		i = 1;
	for (; n[i] != 0; i++)
	{
		if (!isdigit(n[i]))
			return (-1);
	}
	return (0);

}

/**
 * push - push an element to the stack
 * @stack: stack to add to
 * @line_number: line number in monty file
 * @n: value of new node
 */

void push(stack_t **stack, unsigned int line_number, const char *value)
{
	stack_t *new_node;

	if (!stack || is_integer(value) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}

	/* create new node and allocate memory */
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(value); /*give it a value*/
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

	if (!stack || !*stack)
		return;
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

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
