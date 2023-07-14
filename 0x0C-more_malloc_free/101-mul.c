#include <stdio.h>
#include <stdlib.h>

int _isdigit(int c);
int _strlen(char *s);
void _multiply(char *num1, char *num2);
void _print_result(int *result, int size);

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 1; i < argc; i++)
	{
		int j;
		char *arg = argv[i];

		for (j = 0; arg[j] != '\0'; j++)
		{
			if (!_isdigit(arg[j]))
			{
				printf("Error\n");
				return (98);
			}
		}
	}

	_multiply(argv[1], argv[2]);

	return (0);
}

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The string to compute the length of
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * _multiply - Multiplies two numbers and prints the result
 * @num1: The first number
 * @num2: The second number
 */
void _multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *result;
	int size, i, j;

	size = len1 + len2;
	result = calloc(size, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		int n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = result[i + j + 1] + (n1 * n2);

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	_print_result(result, size);

	free(result);
}

/**
 * _print_result - Prints the result of the multiplication
 * @result: The result array
 * @size: The size of the result array
 */
void _print_result(int *result, int size)
{
	int i = 0;

	while (i < size && result[i] == 0)
		i++;

	if (i == size)
		printf("0\n");
	else
	{
		while (i < size)
		{
			printf("%d", result[i]);
			i++;
		}
		printf("\n");
	}
}
