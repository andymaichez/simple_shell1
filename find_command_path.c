#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * find_command_path - Find the executable path for a given command.
 * @dir: The directory to search in.
 * @command: The command to find the path for.
 *
 * Return: The full path to the executable, or NULL if not found.
 */
char *find_command_path(char *dir, char *command)
{
	struct stat st;
	char *full_path = NULL;

	full_path = malloc(sizeof(char) * (strlen(dir) + strlen(command) + 2));
	if (full_path == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	sprintf(full_path, "%s/%s", dir, command);

	if (stat(full_path, &st) == 0)
	{
		if ((st.st_mode & S_IFMT) != S_IFREG)
		{
			free(full_path);
			full_path = NULL;
		}
	}
	else
	{
		free(full_path);
		full_path = NULL;
	}

	return (full_path);
}
