#include <unistd.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *message = "Hello, world!\n";
	ssize_t bytes_written;

	bytes_written = write(STDOUT_FILENO, message, 14);
	if (bytes_written == -1)
	{
		/* Handle error */
		return (1);
	}

	return (0);
}
