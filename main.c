#include "shell.h"
/**
 * main - simple shell
 *
 *@argc : number count of arguments
 *@argv : the arguments
 *
 *Return: 0 always
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		/* Interactive mode */
		interactive_mode();
	}
	else if (argc == 2)
	{
		/* Non-interactive mode */
		non_interactive_mode(argv[1]);
	} else
	{
		write(STDERR_FILENO, "Usage: ", 7);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, " [script_file]\n", 15);
		exit(EXIT_FAILURE);
	}
	return (0);
}

