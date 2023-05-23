#include <unistd.h>
#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _puts - Writes a string to standard output.
 * @str: The string to be written.
 */
void _puts(const char *str)
{
	size_t len = _strlen(str);
	ssize_t bytes_written;

	bytes_written = write(STDOUT_FILENO, str, len);
	if (bytes_written == -1)
	{
		/* Handle error */
		return;
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *message = "Hello, world!\n";

	_puts(message);

	return (0);
}
