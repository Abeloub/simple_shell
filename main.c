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
			free(line);
			return (status);
		}

		command = tokenize_input(line);
		if (!command)
		{
			free(line);
			freearray2D(command);
			continue;
		}
		status = _execute(command, argv);
		free(line);
	}
	return (0);
}

