#include "monty.h"

/**
 * add_node - add a node to a doubly linked list
 * @head: head of list
 * @n: new data to add
 * Return: pointer to newly added node
 */

stack_t *add_node(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = (int)n;

	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (*head);
}

/**
 * delete_node - deletes a node at specified index
 * @head: pointer to first node
 * @index: node position
 * Return: 1 on success otherwise -1
 */

int delete_node(stack_t **head, unsigned int index)
{
	stack_t *current, *temp;
	unsigned int i = 0;

	current = *head;
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next != NULL)
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
			(*head)->prev = NULL;
			return (1);
		}
		if ((*head)->next == NULL)
		{
			free(*head);
			*head = NULL;
			return (1);
		}
	}

	for (; current; current = current->next, i++)
	{
		if (i == index && current->next != NULL)
		{
			current->prev->next = current->next;
			free(current);
			current = NULL;
			return (1);
		}
	}
	return (-1);
}

/**
 * _swap_node - swaps the top two elements in the stack
 * @head: pointer to the top
 * @line_number: commmand line number
 */
void _swap_node(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*head = second;
}

/**
 * stack_len - counts the number of nodes in a double linked list
 * @head: list head
 * Return: number nodes
 */

size_t stack_len(stack_t *head)
{
	stack_t *current;
	size_t i = 0;

	for (current = head; current != NULL; current = current->next)
		i++;

	return (i);
}

/**
 * free_list - frees nodes in a doubly linked list
 * @head: pointer to list end
 */

void free_list(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
		return;

	while (current)
	{
		if (current->next == NULL)
			break;
		current = current->next;
		if (current != NULL || current->prev != NULL)
			free(current->prev);
	}
	free(current);
}
