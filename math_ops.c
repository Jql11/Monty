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
	int sum;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
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
	int difference;


	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = (*stack)->n - (*stack)->next->n;
	(*stack)->next->n = abs(difference);
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;

}

/**
 * _div - divides values of 2 top elements
 * @stack: the stack to assess
 * @line_number: line number from monty
 *
 * Description: divide values of 2 top elements
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (*stack)->n / (*stack)->next->n;
	(*stack)->next->n = quotient;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
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
	int product;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = product;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
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
	int remainder;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	remainder = (*stack)->n % (*stack)->next->n;
	(*stack)->next->n = remainder;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
