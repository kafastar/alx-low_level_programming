#include "main.h"

/**
 * close_files - Closes file descriptors.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 * Return: 0 on success, or one of the error codes on failure.
 */
int close_files(int fd_from, int fd_to)
{
	int err = 0;

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		err = 100;
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		err = 100;
	}

	return (err);
}

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: The arguments vector.
 * Return: 0 on success, or a different number on error.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_from, write_to;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_from == -1 || fd_to == -1)
	{
		dprintf(STDERR_FILENO, fd_from == -1 ?
			"Error: Can't read from file %s\n" :
			"Error: Can't write to %s\n", fd_from == -1 ? argv[1] : argv[2]);
		exit(fd_from == -1 ? 98 : 99);
	}

	while ((read_from = read(fd_from, buffer, 1024)) > 0)
	{
		write_to = write(fd_to, buffer, read_from);
		if (write_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (read_from == -1)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
	exit(close_files(fd_from, fd_to));
}
