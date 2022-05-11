#include "monty.h"

/**
 * add - sums values of 2 top elements
 * @stack: the stack to assess
 * @line_number: line number from monty
 *
 * Description: sum values of 2 top elements
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, sum;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2 || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	(*stack)->prev = NULL;
}

/**
  * sub - subtract values of 2 top elements
  * @stack: the stack to assess
  * @line_number: line number from monty
  *
  * Description: subtract values of 2 top elements
  *
  * Return: void
  */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, difference;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2 || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = (*stack)->n - (*stack)->next->n;
	(*stack)->next->n = difference;
	(*stack)->prev = NULL;

}

/**
 * div - divides values of 2 top elements
 * @stack: the stack to assess
 * @line_number: line number from monty
 *
 * Description: divide values of 2 top elements
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, quotient;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2 || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->n / (*stack)->next->n;
	(*stack)->next->n = quotient;
	(*stack)->prev = NULL;
}

/**
 * mul - multiplies values of 2 top elements
 * @stack: the stack to assess
 * @line_number: line number from monty
 *
 * Description: multiply values of 2 top elements
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, product;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2 || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = product;
	(*stack)->prev = NULL;
}

/**
 * mod - remainder of division of 2 top elements
 * @stack: the stack to assess
 * @line_number: line number from monty
 *
 * Description: modulo value of 2 top elements
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, remainder;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2 || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->n % (*stack)->next->n;
	(*stack)->next->n = remainder;
	(*stack)->prev = NULL;
}
