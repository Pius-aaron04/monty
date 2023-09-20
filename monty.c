#include "monty.h"

stack_t *head = NULL;

/**
 * execute_op - reads and execute opcode
 * @file: file  stream
 * @argv: opcode command
 */

void execute_op(FILE *file, char **argv)
{
	char line[1024];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (strlen(line) <= 1 || strspn(line, " \t\n")
				== (size_t)strlen(line) || line[0] == '#')
			continue;
		argv = tokenize(line, DELIM);
		line_number++;
		get_opcode(argv, line_number);
		free_grid(argv);
	}

}

/**
 * main - entry point
 * @ac: number of command line argument
 * @argv: arguments passed
 * Return: Exit status
 */

int main(int ac, char **argv)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r+");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute_op(file, argv);
	fclose(file);
	return (EXIT_SUCCESS);
}
