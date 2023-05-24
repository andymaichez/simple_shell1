#include <unistd.h>
#include "shell.h"

/**
 * env_shell -Execute the built-in command "env"
 *
 */
void env_shell(void)
{
	int i = 0;
	char *env_var;
	char **environ;

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		write(STDOUT_FILENO, env_var, strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

