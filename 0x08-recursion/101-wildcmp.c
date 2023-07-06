#include "main.h"

/**
 * wildcmp - Compares two strings for identity with wildcard support
 * @s1: The first string.
 * @s2: The second string (can contain the special character '*').
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 == '\0' || *s2 == '*')
			return (1);
		else
			return (0);
	}

	if (*s2 == '*')
	{
		if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}
	else if (*s1 == *s2)
	{
		if (wildcmp(s1 + 1, s2 + 1))
			return (1);
	}

	return (0);
}
