#include "monty.h"

/**
 * tokenize - tokenizes a stream of characters
 * @str: string to tokenize
 * @delim: delimiter
 * Return: array to tokens
 */

char **tokenize(char *str, const char *delim)
{
	char **words, *cpy, *token;
	int i = 0, num_tokens = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	cpy = malloc(sizeof(char) * strlen(str) + 1);
	if (cpy == NULL)
		return (NULL);
	strcpy(cpy, str);
	token = strtok(str, delim);

	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	words = malloc(sizeof(char *) * num_tokens);
	if (words == NULL)
		return (NULL);
	token = strtok(cpy, delim);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		words[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(words[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	words[i] = NULL;
	free(cpy);
	return (words);
}

/**
 * free_grid - deallocates a 2D array
 * @grid: a 2D aray pointer
 * Return: Nothing
 */

void free_grid(char **grid)
{
	char **grid_cpy = grid;

	while (*grid != NULL)
	{
		free(*grid);
		grid++;
	}
	free(grid_cpy);
}
