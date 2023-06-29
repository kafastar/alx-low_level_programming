#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to encode
 *
 * Return: Pointer to the modified string
 */
char *leet(char *str)
{
	int i, j;
	char leet_letters[] = "aeotl";
	char leet_numbers[] = "43071";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet_letters[j] != '\0'; j++)
		{
			if (str[i] == leet_letters[j] || str[i] == leet_letters[j] - 32)
				str[i] = leet_numbers[j];
		}
	}

	return (str);
}
