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
	FILE *fd = NULL;
	unsigned int line = 1;
	char *buffer = NULL, *token = NULL;

	fd = fopen(argv, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fd) != -1)
	{
		token = strtok(buffer, " \n\t\a\r");
		if (token == NULL)
			continue;
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
	free(buffer);
	free_dlistint(stack);
	fclose(fd);
}



