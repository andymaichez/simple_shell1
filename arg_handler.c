#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	char *prompt = "#cisfun$ ";
	ssize_t bytes_written = write(STDOUT_FILENO, prompt, strlen(prompt));
		if (bytes_written == -1)
		{
			perror("write error");
			exit(EXIT_FAILURE);
		}
}

/**
 * parse_arguments - Tokenize the command line and extract the arguments.
 * @command: The command line to parse.
 * @argc: Pointer to store the number of arguments.
 *
 * Return: An array of arguments.
 */
char **parse_arguments(char *command, int *argc)
{
	char *arg;
	char **args = malloc(sizeof(char *) * MAX_ARGS);
		if (!args)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

	arg = strtok(command, " \t\n");
	*argc = 0;
	while (arg != NULL && *argc < MAX_ARGS - 1)
	{
		args[*argc] = arg;
		(*argc)++;
		arg = strtok(NULL, " \t\n");
	}
	args[*argc] = NULL;

	return (args);
}

/**
 * execute_command - Execute a command with the given arguments.
 * @args: An array of arguments.
 */
void execute_command(char **args)
{
	pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
			waitpid(pid, &status, 0);
	}
}

/**
 * run_shell - Run the shell program.
 */
void run_shell(void)
{
	while (1)
	{
		char *command;
		int argc;
		char **args;

		display_prompt();
		command = malloc(sizeof(char) * BUFFER_SIZE);
			if (!command)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}

	if (fgets(command, BUFFER_SIZE, stdin) == NULL)
	{
		free(command);
		if (is_interactive_mode())
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(EXIT_SUCCESS);
	}

	args = parse_arguments(command, &argc);
		if (argc > 0)
		execute_command(args);

		free(command);
		free(args);
	}
}
