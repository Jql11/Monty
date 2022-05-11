#include "main.h"
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
	char *buffer;
	FILE *fd;
	size_t bufsize = 0;
	unsigned int line = 1;
	stack_t *stack = NULL;

	fd = fopen(argv, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fd) != -1)
	{
		_token(buffer);
		line++;
	}
	free_dlistint(&stack);
	free(buffer);
	fclose(fd);
}



