#include "main.h"
/**
  *main - main function
  *@ac: number of argument
  *@argv: argument
  *Return: 0 on success
  */
int main(int ac, char *argv[])
{
	char *buffer, *token;
	size_t bufsize = 0;
	FILE *fd;
	unsigned int line = 1;
	stack_t *h = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " \n\t\a\r");
	if (getline(&buffer, &bufsize, fd) != -1)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t\a\r");
			continue;
		}
		else
		{
			if (ops(token) != 0)
				ops(token)(&h, line);
			else
			{
				free_dlistint(&h);
				free(buffer);
				fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, " \n\t\a\r");
	}
	free_dlistint(&h);
	free(buffer);
	fclose(fd);
	return (0);
}
