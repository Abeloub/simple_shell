Simple Shell
This project is a simple UNIX command line interpreter, or "Shell", written in C. The shell takes user commands and interprets them into instructions that the operating system can understand. This shell replicates some of the basic functionalities of a typical shell, including handling command lines with arguments, managing the PATH, implementing built-ins like "cd", "exit", and "env", and more.

Features
Displays a prompt and waits for the user to type a command, which always ends with a newline.
The prompt is displayed again each time a command has been executed.
Handles command lines with arguments, not just single-word commands.
Manages the PATH, so you can call programs from anywhere without specifying the full path.
Implements built-in commands: 'cd', 'exit', 'env', 'setenv', 'unsetenv'.
Handles the "end of file" condition (Ctrl+D).
Prints a custom error message when an executable cannot be found.
If a command cannot be found, it will print an error message and display the prompt again.


Compilation
The shell is compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
The shell works in both interactive and non-interactive mode.

In interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
In non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$


