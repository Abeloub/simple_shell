#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 *
 * @variable: The name of the environment variable.
 *
 * Return: If the variable is found, return its value; otherwise, return NULL.
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}

/**
 * _handle_path - Handle the command path resolution.
 *
 * @command: The command to be resolved.
 *
 * Return: If the command is found in the PATH, return the full path;
 * otherwise, return NULL.
 */
char *_handle_path(char *command)
{
	char *path_env = NULL;
	char *full_command = NULL;
	char *dir = NULL;
	int i = 0;
	struct stat st;

for (i = 0, command[i], i++)
{
	if (command[i] == '/')
	{
		if (stat(command, &st) == 0)
			return (_strdup(command));

		return (NULL);
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_command = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_command)
		{
			_strcpy(full_command, dir);
			_strcat(full_command, "/");
			_strcat(full_command, command);
			if (stat(full_command, &st) == 0)
			{
				free(path_env);
				return (full_command);
			}
			free(full_command), full_command = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

