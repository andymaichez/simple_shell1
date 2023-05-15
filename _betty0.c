#include <stdio.h>

/**
 * calculate_triangle_sum - Calculates the sum of a right-angled triangle.
 * @base: The base of the triangle.
 * @height: The height of the triangle.
 *
 * Return: The calculated sum.
 */
double calculate_triangle_sum(double base, double height)
{
	double sum;

	sum = 0.5 * base * height;

	return (sum);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	double base, height, sum;

	printf("Enter the base of the triangle: ");
	scanf("%lf", &base);

	printf("Enter the height of the triangle: ");
	scanf("%lf", &height);

	sum = calculate_triangle_sum(base, height);

	printf("The sum of the right-angled triangle is: %.2lf\n", sum);

	return (0);
}
