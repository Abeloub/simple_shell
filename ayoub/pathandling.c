#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define TOK_DELIM " \t\r\n\a"

char *find_executable(const char *command) {
    char *path = getenv("PATH");
    if (path == NULL) {
        return NULL; // PATH variable not set
    }

    char *token;
    char *path_copy = strdup(path); // Duplicate PATH for tokenization
    if (path_copy == NULL) {
        return NULL; // Memory allocation error
    }

    token = strtok(path_copy, ":");
    while (token != NULL) {
        char *executable_path = malloc(MAX_PATH_LENGTH);
        if (executable_path == NULL) {
            free(path_copy);
            return NULL; // Memory allocation error
        }

        strcpy(executable_path, token);
        strcat(executable_path, "/");
        strcat(executable_path, command);

        if (access(executable_path, X_OK) == 0) {
            free(path_copy);
            return executable_path; // Return executable path if found
        }

        free(executable_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL; // Executable not found in any PATH directory
}

int main() {
    char *command = "ls"; // Example command
    char *executable_path = find_executable(command);
    if (executable_path != NULL) {
        printf("Executable path: %s\n", executable_path);
        free(executable_path);
    } else {
        printf("Executable not found in PATH.\n");
    }

    return EXIT_SUCCESS;
}
