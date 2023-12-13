#include "shell.h"

/**
 * execute_command - execute a command using fork and execve
 *@args: argument of function
 *
 *Return: void
 */

void execute_command(char **args)
{
	pid_t pid, wait_pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror(args[0]);
	}
	else
	{
		/* Parent process */
		{
			do
			wait_pid = waitpid(pid, &status, WUNTRACED);

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}

/**
 * tokenize_input - tokenize the command input into * * separate words
 *@input: command input
 *
 *Return: the number of tokens
 */

char **tokenize_input(char *input)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!input)
		return (NULL);
	tmp = _strdup(input);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(input), input = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(input), input = NULL;
		return (NULL);
	}
	token = strtok(input, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	return (command);
}

