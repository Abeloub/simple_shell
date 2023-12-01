#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define RL_BUFSIZE 1024

/**
 * oursh_read_line - Read a line of input
 * Return: Pointer to the input line
 */
char *oursh_read_line(void) {
    int bufsize = RL_BUFSIZE;  // Initial buffer size
    int position = 0;              // Current position in the buffer
    char *buffer = malloc(sizeof(char) * bufsize);  // Allocate initial memory for buffer
    int c;                         // Variable to store input character

    if (!buffer) {
        // Print allocation error and exit on failure
        write(STDERR_FILENO, "sh: allocation error\n", 21);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a character
        c = getchar();

        // If we hit EOF or newline, replace with null character and return
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If exceeded buffer, reallocate memory
        if (position >= bufsize) {
            bufsize += RL_BUFSIZE;  // Increase buffer size
            buffer = realloc(buffer, bufsize);  // Reallocate memory
            if (!buffer) {
                // Print allocation error and exit on failure
                write(STDERR_FILENO, "sh: allocation error\n", 21);
                exit(EXIT_FAILURE);
            }
        }
    }
}

