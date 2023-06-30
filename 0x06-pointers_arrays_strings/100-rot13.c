#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 encryption.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	int i;
	char *ptr = str;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (*ptr)
	{
		for (i = 0; alpha[i]; i++)
		{
			if (*ptr == alpha[i])
			{
				*ptr = rot13[i];
				break;
			}
		}
		ptr++;
	}

	return str;
}
