#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define PROMPT "$ "

/**
 * execute_command - Execute the given command using execve
 * @command: The command to execute
 * It handles the child and parent processes accordingly.
 */
void execute_command(char *command)
{
	pid_t pid;

	char *args[2];
	int status;

	args[0] = command;
	args[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * read_command - Read a command from the user
 *
 * Return: The command string, or NULL if end-of-file (Ctrl+D) is encountered
 */
char *read_command()
{
	char buffer[BUFFER_SIZE];

	printf("%s", PROMPT);
	fflush(stdout);

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		printf("\n");
		return (NULL); /* Handle end-of-file (Ctrl+D) */
	}

	buffer[strcspn(buffer, "\n")] = '\0'; /* Remove trailing newline */

	return (strdup(buffer));
}

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		command = read_command();

		if (command == NULL)
		break;

		execute_command(command);

		free(command);
	}

	return (0);
}
