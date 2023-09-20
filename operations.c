#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: head of the list
 * @line_number: command line number
 */

void add(stack_t **head, unsigned int line_number)
{
	int result;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result  = (*head)->n + (*head)->next->n;
	pop(head, line_number);
	pop(head, line_number);
	add_node(head, result);
}

/**
 * sub - subtracts the top element from the second element on the stack
 * @head: head of the list
 * @line_number: command line
 */
void sub(stack_t **head, unsigned int line_number)
{
	int result;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result  = (*head)->next->n - (*head)->n;
	pop(head, line_number);
	pop(head, line_number);
	add_node(head, result);
}

/**
 * _div - divides the second top element by the second element of the stack
 * @head: head of the list
 * @line_number: command line
 */
void _div(stack_t **head, unsigned int line_number)
{
	int result;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*head);
		free_grid(opcode_read);
		exit(EXIT_FAILURE);
	}
	result  = (*head)->next->n / (*head)->n;
	pop(head, line_number);
	pop(head, line_number);
	add_node(head, result);
}

/**
 * mul - mul the top element by the second element of the stack
 * @head: head of the list
 * @line_number: command line
 */
void mul(stack_t **head, unsigned int line_number)
{
	int result;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_list(*head);
		free_grid(opcode_read);
		exit(EXIT_FAILURE);
	}
	result  = (*head)->next->n * (*head)->n;
	pop(head, line_number);
	pop(head, line_number);
	add_node(head, result);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: head of the list
 * @line_number: command line
 */
void mod(stack_t **head, unsigned int line_number)
{
	int result;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_list(*head);
		free_grid(opcode_read);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*head);
		free_grid(opcode_read);
		exit(EXIT_FAILURE);
	}
	result  = (*head)->next->n % (*head)->n;
	pop(head, line_number);
	pop(head, line_number);
	add_node(head, result);
}
