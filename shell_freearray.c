#include "shell.h"
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

