#include <stdlib.h>
#include <stdio.h>

/**
 * exit_shell - Terminate the shell
 *
 * Description: This function is responsible for terminating the shell
 * and performing any necessary cleanup or finalization steps.
 */
void exit_shell(void)
{
	printf("Exiting shell...\n");
	/* Perform any necessary cleanup or finalization steps here */

	exit(EXIT_SUCCESS);
}
