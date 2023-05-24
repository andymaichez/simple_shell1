#include "shell.h"

/**
 * find_command_path - Finds the full path of a command in the directories list
 * @command: The command name
 *
 * Return: The full path of the command if found, NULL otherwise
 */
char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *dir, *path_copy, *full_path;
	struct stat st;

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = find_command_path(dir, command);

		if (full_path && strcat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * build_command_path - Builds the full path of a command
 * @dir: The directory path
 * @command: The command name
 *
 * Return: The full path of the command, or NULL on failure
 */
char *build_command_path(char *dir, char *command)
{
	int dir_len = strlen(dir);
	int command_len = strlen(command);
	char *full_path;
	int i;

	full_path = malloc(sizeof(char) * (dir_len + command_len + 2));
	if (!full_path)
		return (NULL);

	for (i = 0; i < dir_len; i++)
		full_path[i] = dir[i];
	full_path[i] = '/';
	for (i = 0; i < command_len; i++)
		full_path[dir_len + 1 + i] = command[i];
	full_path[dir_len + 1 + i] = '\0';

	return (full_path);
}
