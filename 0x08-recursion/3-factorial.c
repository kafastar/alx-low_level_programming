#include "main.h"

/**
 * factorial - Returns the factorial of a number.
 * @n: The number to calculate the factorial of.
 *
 * Return: The factorial of the number.
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
