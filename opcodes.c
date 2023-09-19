#include "monty.h"


/**
 * push - push integer to the top of the stack
 * @head: pointer to stack head
 * @operand: integer to push
 */

void push(stack_t **head, int operand)
{
	add_node(head, operand);
}


/**
 * pall - print all integer on top of the stack
 * @head: pointer to stack head
 * @line_number: command line number
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;

	(void)line_number;
	if (current == NULL)
		return;
	for (; current != NULL; current = current->next)
		printf("%d\n", current->n);
}

/**
 * pint - print integer top element of the stack
 * @head: pointer to stack head
 * @line_number: command line number
 */

void pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes element from the top of the stack
 * @head: pointer to stack head
 * @line_number: command line number
 */

void pop(stack_t **head, unsigned int line_number)
{
	if (delete_node(head, 0) == -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack",
				line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to stack head
 * @line_number: command line number
 */

void swap(stack_t **head, unsigned int line_number)
{
	_swap_node(head, line_number);
}
