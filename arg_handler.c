#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * handle_command - Handle the command provided by the user.
 * @args: The arguments of the command.
 * @command: the command string
 */
void handle_command(char **args, char *command)
{

	if (args[0] != NULL)
	{
		execute_command(args, command);
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
 * @command: The command string (unused)
 */
void execute_command(char **args, char *command)
{

	pid_t pid;
	(void)command;
	pid = fork();
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
