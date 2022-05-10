#include "main.h"
/**
  *main - main function
  *@ac: number of argument
  *@argv: argument
  *Return: 0 on success
  */
int main(int ac, char *argv[])
{
	char *buffer;
	int fd;
	size_t bufsize = 0;
	unsigned int line = 1;
	stack_t *h = NULL;

	if (ac < 1)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fd) != -1)
	{
		token = strtok(buffer, " \n\t\a\r");
		if (token == NULL)
		{
			free(token);
			return (NULL);
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
				if (ops != 0)
					ops(&h, line, token);
				else
				{
					free_dlist(&h);
					free(buffer);
					dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, token);
					close(fd);
					exit(EXIT_FAILURE);
				}
			}
			line++;
			token = strtok(NULL, " \n\t\a\r");
		}

	}
	free_dlist(&h);
	free(buffer);
	close(fd);
	return (0);


}
