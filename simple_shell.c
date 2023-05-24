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
void display_prompt(void) /* display_prompt - Display the shell prompt */
{
	if (is_interactive_mode())
		printf("$ ");
}

/**
 * read_command - Read a command from the user.
 *
 * Return: The command entered by the user.
 */
char *read_command(void)
{
	char *command = malloc(sizeof(char) * BUFFER_SIZE);
		if (!command)
		{
		perror("malloc error");
		exit(EXIT_FAILURE);
		}

	if (fgets(command, BUFFER_SIZE, stdin) == NULL)
	{
		free(command);
		if (is_interactive_mode())
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	return (command);
}

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid_t pid;
		pid = fork();
		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve error");
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
 * run_shell - Run the shell.
 */
void run_shell(void)
{
	while (1)
	{
		display_prompt();
		char *command = read_command();
			if (strlen(command) > 0)
			{
				command[strcspn(command, "\n")] = '\0';
				execute_command(command);
			}
			free(command);
	}
}

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	run_shell();
	return (EXIT_SUCCESS);
}
