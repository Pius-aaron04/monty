#include "monty.h"

char **opcode_read = NULL;

/**
 * execute_op - reads and execute opcode
 * @file: file  stream
 * @head: pointer to list head
 */

void execute_op(FILE *file, stack_t **head)
{
	char line[1024];
	char ***argv = &opcode_read;
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		/*Handles multiple white spaces and lines*/
		if (strlen(line) <= 1 || strspn(line, " \t\n")
				== (size_t)strlen(line) || line[0] == '#')
			continue;
		*argv = tokenize(line, DELIM);
		line_number++;
		if (*argv == NULL)
		{
			/*cleanup before leaving*/
			fprintf(stderr, "Error: malloc failed\n");
			free_grid(*argv);
			free_list(*head);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		get_opcode(head, line_number);
		free_grid(*argv);
	}
	free_list(*head);
}

/**
 * main - entry point
 * @ac: number of command line argument
 * @argv: arguments passed
 * Return: Exit status
 */

int main(int ac, char **argv)
{
	stack_t *head = NULL;
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
	execute_op(file, &head);
	fclose(file);
	return (EXIT_SUCCESS);
}
