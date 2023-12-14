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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);

		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * print_error - read a line from the standard input
 *
 *@name: A string is name of the program or shell
 *@command: string is the command that was not found
 *@i: is a number or index associated with the error
 *
 * Return: the number of characters read, or -1 on failure
 */
void print_error(char *name, char *command, int i)
{
	char *andex;
	char mesage[] = ": not found\n";

	andex = _itoa(i);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, andex, _strlen(andex));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, mesage, _strlen(mesage));

	free(andex);
}


/**
 * _itoa - Convert an integer to a string.
 *
 * @n: The integer to be converted.
 *
 * Return: A dynamically allocated string representing the integer.
 */
char *_itoa(int n)
{
	char  buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverse_string - read a line from the standard input
 *
 *@str: pointer to the string that you want to reverse.
 *@len: integer representing the length of the string.
 *
 * Return: the number of characters read, or -1 on failure
 */
void reverse_string(char *str, int len)
{
	char tremp;
	int beginn = 0;
	int finish = len - 1;

	while (beginn < finish)
	{
		tremp = str[beginn];
		str[beginn] = str[finish];
		str[finish] = tremp;
		beginn++;
		finish--;
	}
}


