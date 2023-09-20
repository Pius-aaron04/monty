#include "monty.h"

/**
 * _isdigit - checks leading character of operand read
 * @s: leading character of operand read
 * Return: 1 if true else 0
 */
int _isdigit(char s)
{
	if (!(s >= '0' && s <= '9'))
		return (0);
	return (1);
}

/**
 * get_opcode - gets and executes opcode
 * @head: pointer to list head
 * @line_number: command line number
 */

void get_opcode(stack_t **head, unsigned int line_number)
{
	int l = 0;
	instruction_t opcodes[] = {
		{"nop", nop},
		{"pall", pall},
		{"pint", pint}, {"swap", swap},
		{"pop", pop}};

	while (l < 5)
	{
		if (strcmp((const char *)opcode_read[0], "push") == 0)
		{
			if (!opcode_read[1])
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_grid(opcode_read);
				free_list(*head);
				exit(EXIT_FAILURE);
			}
			push(head, opcode_read[1], line_number);
			return;
		}
		if (strcmp((const char *)opcode_read[0],
					(const char *)opcodes[l].opcode) == 0)
		{
			opcodes[l].f(head, line_number);
			return;
		}
		l++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_read[0]);
	free_list(*head);
	free_grid(opcode_read);
	exit(EXIT_FAILURE);
}
