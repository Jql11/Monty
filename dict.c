#include "monty.h"

/**
 * ops - dictionary of functions
 * @opcode: opcode
 *Return: ops
 */
void (*ops(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/*	{"swap", swap}, */
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
