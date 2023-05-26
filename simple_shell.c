#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * is_interactive_mode - Check if the shell is running in interactive mode.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int is_interactive_mode(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * display_prompt- Display the shell prompt
 */
void display_prompt(void)
{
	if (is_interactive_mode())
	printf("#cisfun$");
}

/**
 * read_command - reads the command entered by user
 *
 * Return: The command line input as a string, or NULL on end of file
 */
char *read_command(void)
{
	char *buffer = malloc(BUFFER_SIZE);
		if (!buffer)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}

/**
 * run_shell - Run the shell.
 *
 */
void run_shell(void)
{
	char *command;
	int argc;
	char **args;

	while (1)
	{
		display_prompt();
		command = read_command();
		args = parse_arguments(command, &argc);
		handle_command(args, command);

		free(command);
		free(args);
	}
}
