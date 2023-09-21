#include "monty.h"

/**
 * pstr - prints string starting at the top of the stack
 * @head: head of a list
 * @line_number: command line number
 */

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *node = *head;

	(void)line_number;
	for (; node; node = node->next)
	{
		if (node->n >= 0 && node->n <= 127)
		{
			if (node->n == 0)
				break;
			putchar(node->n);
		}
	}
	putchar('\n');
}
