#include "monty.h"

/**
 * nop - does nothing
 * @head: head to the list
 * @line_number: command line number
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * rotl - makes the second first and first last
 * @head: head to the list
 * @line_number: command line number
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *second, *tail, *first;

	/*Checks if stack is empty or has one element*/
	if ((!*head) || (*head && !(*head)->next))
		return;
	/*calls swap intead if it's just two elements*/
	if (stack_len(*head) == 2)
	{
		swap(head, line_number);
		return;
	}
	else
	{
		first = tail = *head;
		second = (*head)->next;
		while (tail->next)
			tail = tail->next;
		tail->next = first;
		first->next = NULL;
		first->prev = tail;
		second->prev = NULL;
		*head = second;
		return;
	}
}

/**
 * rotr - rotates the stack
 * @head: head to the list
 * @line_number: command line number
 */

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *top, *temp, *bottom;

	(void)line_number;
	if (!*head)
		return;
	if (!*head || !(*head)->next)
		return;

	bottom = *head;
	while (bottom)
	{
		top = bottom;
		temp = bottom->next;
		bottom->next = bottom->prev;
		bottom->prev = temp;
		bottom = temp;
	}
	*head = top;
}

/**
 * stack - switches data structure order mode
 * @line_number: command line number
 * @head: pointer to list head
*/

void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}


/**
 * pchar - prints the string starting at the top of the stack
 * @head: head of the list
 * @line_number: command line number
 */

void pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n >= 0 && (*head)->n <= 127)
	{
		putchar((*head)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_list(*head);
		free_grid(opcode_read);
		exit(EXIT_FAILURE);
	}
}
