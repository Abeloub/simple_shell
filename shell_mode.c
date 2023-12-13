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
	int is_interactive = isatty(STDIN_FILENO);

	if (is_interactive)
		write((STDOUT_FILENO), prompt, _strlen(prompt));

	n = getline(&line, &len, stdin);

	if (n == -1) /* end of file condition */
	{
		if (is_interactive)
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		return (NULL);
	}

	if (is_interactive)
	{
		/*Null-terminate the string for interactive mode*/
		if (line[n - 1] == '\n')
			line[n - 1] = '\0'; /*(remove newline)*/
	}
	else
	{
		/*Null-terminate the string for non-interactive mode*/
		if (line[n - 1] == '\n')
			line[n - 1] = '\0';
		else
			line[n] = '\0';
	}
	return (line);
}

