#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring.
 * @haystack: The string to search in.
 * @needle: The substring to find.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	/* Return haystack if needle is empty */
	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		/* Check if current character matches needle's first character */
		if (haystack[i] == needle[0])
		{
			/* Check if the following characters match the rest of the needle */
			for (j = 1; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}

			/* If the entire needle is found, return the current position in haystack */
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
	}

	return (NULL); /* Substring not found */
}
