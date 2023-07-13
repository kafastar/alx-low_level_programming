#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes of s2 to concatenate
 * Return: a pointer to the concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2, i, j;

	/* check if s1 or s2 are NULL and treat them as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* find the length of s1 and s2 */
	for (len1 = 0; s1[len1]; len1++)
		;
	for (len2 = 0; s2[len2]; len2++)
		;

	/* if n is greater or equal to the length of s2, use the entire s2 */
	if (n >= len2)
		n = len2;

	/* allocate memory for the concatenated string */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL) /* check if malloc failed */
		return (NULL);

	/* copy s1 into concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* copy n bytes of s2 into concat */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* add the null-terminating character */
	concat[i] = '\0';

	/* return the pointer to the concatenated string */
	return (concat);
}
