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

extern char **environ;

/* shell command function */
char **tokenize_input(char *input);
int _execute(char **command, char **argv, int andex);
char *read_line(void);
void freearray2D(char **arr);

/* string function */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* handle the path */
char *_getenv(char *variable);
char *_handle_path(char *command);

void print_error(char *name, char *command, int i);
char *_itoa(int n);
void reverse_string(char *str, int len);

#endif /* SHELL_H */


