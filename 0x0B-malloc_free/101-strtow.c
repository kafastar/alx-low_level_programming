#include <stdlib.h>

int count_words(char *str);
int word_length(char *str);
char **allocate_memory(int num_words);
void free_memory(char **words, int num_words);

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, num_words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = allocate_memory(num_words);
	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}

		len = word_length(str + i);
		words[k] = malloc((len + 1) * sizeof(char));
		if (words[k] == NULL)
		{
			free_memory(words, k);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[i++];

		words[k][j] = '\0';
		k++;
	}

	words[k] = NULL;
	return (words);
}

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: Number of words in the string
 */
int count_words(char *str)
{
	int count = 0;
	int is_word = 0;

	while (*str != '\0')
	{
		if (*str == ' ')
		{
			is_word = 0;
		}
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}

		str++;
	}

	return (count);
}

/**
 * word_length - Calculates the length of a word
 * @str: The string containing the word
 *
 * Return: Length of the word
 */
int word_length(char *str)
{
	int length = 0;

	while (*str != ' ' && *str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * allocate_memory - Allocates memory for an array of words
 * @num_words: The number of words in the array
 *
 * Return: Pointer to the allocated memory
 */
char **allocate_memory(int num_words)
{
	char **words;

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * free_memory - Frees the memory allocated for an array of words
 * @words: The array of words
 * @num_words: The number of words in the array
 *
 * Return: Nothing
 */
void free_memory(char **words, int num_words)
{
	int i;

	for (i = 0; i < num_words; i++)
		free(words[i]);

	free(words);
}
