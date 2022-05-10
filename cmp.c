#include main.h

/**
 * ops - dictionary of functions
 * @stack:
 * @line_number:
 * @opcode:
 * Description:
 * Return: pointer to function
 */

void ops(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push};
		{"pall", pall};
		{"pint", pint};
		{"pop", pop};
		{"swap", swap};
		{"add", add};
		{"nop", nop};
		{NULL, NULL};
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode == 0))
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	return (NULL);
}
