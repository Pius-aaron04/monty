#include "monty.h"

/**
 * get_opcode - gets and executes opcode
 * @opcode_read: opcode read from file
 * @line_number: command line number
 */

void get_opcode(char **opcode_read, unsigned int line_number)
{
	int l = 0;
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint}, {"swap", swap},
		{"pop", pop}};

	while (l < 4)
	{
		if (strcmp((const char *)opcode_read[0], "push") == 0)
		{
			push(&head, atoi(opcode_read[1]));
			return;
		}
		if (strcmp((const char *)opcode_read[0],
					(const char *)opcodes[l].opcode) == 0)
		{
			opcodes[l].f(&head, line_number);
			return;
		}
		l++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_read[0]);
	exit(EXIT_FAILURE);
}
