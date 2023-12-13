#include "shell.h"

/**
 * read_line - read a line from the standard input
 *
 *
 * Return: the number of characters read, or -1 on failure
 */

char *read_line(void)
{
	char *prompt = "#cisfun$ ";
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	/* Check if input is from a terminal */
	if (isatty(STDIN_FILENO))
		write((STDOUT_FILENO), prompt, _strlen(prompt));

	n = getline(&line, &len, stdin);

	if (n == -1) /* end of file condition */
	{
		
		free(line);
		return (NULL);
	}

	return (line);
}


