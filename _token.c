#include "monty.h"
/**
  *_token - token opcode
  *@buffer: buffer;
  *Return: 0 on success, -1 if failed
  */
int _token(char *buffer)
{
	char *token, *value;
	unsigned int line = 1;
	stack_t *stack = NULL;

		token = strtok(buffer, " \n\t\a\r");
		if (token == NULL)
			return (-1);
		else if (*token == '#')
			return (-1);
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n\t\a\r");
			if (value == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			push(&stack, line, value);
		}
		else
		{
			ops(token, &stack, line);
		}
		return (0);
}

