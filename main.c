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
	int andex = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL) /*reache end of file (ctrl + D)*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (status);
		}

		andex++;
		command = tokenize_input(line);
		if (!command)
		{
			freearray2D(command);
			continue;
		}
	
		if (strcmp(command[0], "exit") == 0)
		{
		freearray2D(command);
		free(line);
		exit(EXIT_SUCCESS);
		}

		status = _execute(command, argv, andex);
	}
	return (0);
}



