#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to capitalize
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else
			{
				for (j = 0; separators[j] != '\0'; j++)
				{
					if (str[i - 1] == separators[j])
					{
						str[i] -= 32;
						break;
					}
				}
			}
		}
	}

	return (str);
}
