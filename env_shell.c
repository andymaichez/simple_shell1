#include "shell.h"
#include <stdlib.h>

/**
 * env_shell - Execute the built-in command "env"
 * @environ: environ -External variable containing the environment variables
 */
void env_shell(char **environ)
{
	int i = 0;
	char *env_var;

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		/* Write the environment variable to standard output */
		write(STDOUT_FILENO, env_var, strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

