#include "shell.h"

/**
 * main - simple shell
 *
 *@ac : number count of arguments
 *@argv : the arguments
 *
 *Return: 0 always
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void) argv;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL) /*reache end of file (ctrl + D)*/
		{
			if (isatty(STDIN_FILENO))
				write((STDOUT_FILENO), "\n", 1);
			return (status);
		}

		command = tokenizer(line);
		if (!command)
			continue;

		status = _execute(command, argv);
	}
}
