#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
 * calculate_triangle_sum - Calculates the sum of a right-angled triangle.
 * @base: The base of the triangle.
 * @height: The height of the triangle.
 *
 * Return: The calculated sum.
 */
int calculate_triangle_sum(int base, int height)
{
	int sum;

	sum = (base * height) / 2;

	return (sum);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	int base, height, sum;
	char base_str[10], height_str[10], sum_str[10];

	write(STDOUT_FILENO, "Enter the base of the triangle: ", 32);
	read(STDIN_FILENO, base_str, sizeof(base_str));
	base = atoi(base_str);

	write(STDOUT_FILENO, "Enter the height of the triangle: ", 34);
	read(STDIN_FILENO, height_str, sizeof(height_str));
	height = atoi(height_str);

	sum = calculate_triangle_sum(base, height);

	sprintf(sum_str, "%d\n", sum);
	write(STDOUT_FILENO, "The sum of the right-angled triangle is: ", 41);
	write(STDOUT_FILENO, sum_str, strlen(sum_str));

	_exit(0);
}
