#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/* shell command function */
char **tokenize_input(char *input);
void execute_command(char **args);
char *read_line(void);

/*shell mode function*/
void interactive_mode(void);
void non_interactive_mode(char *script_filename);

/* string function */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);



#endif /* SHELL_H */

