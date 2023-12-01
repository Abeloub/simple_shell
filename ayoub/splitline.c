#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * oursh_split_line - Splits a line into tokens
 * @line: Input string to be tokenized
 *
 * Return: Array of tokens
 */
char **oursh_split_line(char *line)
{
	int bufsize = TOK_BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
	write(STDERR_FILENO, "sh: allocation error\n", 21);
	exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;

		if (position >= bufsize)
		{
		bufsize += TOK_BUFSIZE;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
		write(STDERR_FILENO, "sh: allocation error\n", 21);
		exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
