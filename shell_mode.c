#include "shell.h"
/*
 * interactive_mode - shell in interactive mode
 *
 *Return: 0
 */

void interactive_mode(void) 
{
	char *input;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "$$- ", 4);
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}

		/* Remove newline character */
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			/* Exit the shell */
			free(input);
			exit(EXIT_SUCCESS);
		}

		char **args = tokenize_input(input);

		if (args[0] != NULL)
		{
			execute_command(args);
		}

		free(args);
	}
	free(input);
}

/*
 * non_interactive_mode - shell in non interactive mode
 *
 *Return: 0
 */

void non_interactive_mode(char *script_filename)
{
	FILE *script_file = fopen(script_filename, "r");

	if (script_file == NULL)
	{
		perror("shell");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, script_file)) != -1)
	{
		/* Remove newline character */
		line[strcspn(line, "\n")] = 0;

		char **args = tokenize_input(line);

		if (args[0] != NULL)
		{
			execute_command(args);
		}

		free(args);
	}
	free(line);
	fclose(script_file);
}

