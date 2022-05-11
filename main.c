#include "monty.h"
/**
  *main - main function
  *@ac: number of argument
  *@argv: argument
  *Return: 0 on success
  */
int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	handle_command(argv[1]);
	return (0);
}
/**
 * handle_command - Read file
 * @argv: Arguments
 */
void handle_command(char *argv)
{
	stack_t *stack = NULL;
	size_t bufsize = 0;
	FILE *fd;
	unsigned int line = 1;
	char *buffer, *token, *value;

	fd = fopen(argv, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fd) != -1)
	{
		token = strtok(buffer, " \n\t\a\r");
		if (token == NULL || *token == '#')
			continue;
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n\t\a\r");
			push(&stack, line, value);
		}
		else
		{
			if (!ops(token))
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			else
				ops(token)(&stack, line);
		}
		line++;
	}
	free_dlistint(&stack);
	free(buffer);
	fclose(fd);
}



