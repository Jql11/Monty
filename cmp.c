#include "main.h"

/**
 * ops - dictionary of functions
 * @stack:
 * @line_number:
 * @opcode:
 * Description:
 * Return: pointer to function
 */

void ops(char *opcode, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
/*		{"swap", swap}, 
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			printf("there is match ops\n");
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
