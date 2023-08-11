#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Name of the file
 * @letters: Number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 if the file
 *         could not be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t ret;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	ret = read(fd, buf, letters);
	if (ret == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	if (write(STDOUT_FILENO, buf, ret) == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	if (close(fd) == -1)
		return (0);

	return (ret);
}
