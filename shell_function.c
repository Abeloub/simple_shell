#include "shell.h"

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

/**
 * _execute - execute a command using fork and execve
 *@command: command text line
 *@argv: argument of function
 *
 *Return: void
 */

int _execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearray2D(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray2D(command);
	}
	return (WEXITSTATUS(status));
}

/**
 * freearray2D -  free array of strings
 * @arr: 2d array of comand
 *
 **/

void freearray2D(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	}
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}


