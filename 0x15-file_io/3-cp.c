#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * check_errors - Check for the potential errors and handle them.
 * @file_from: File descriptor for source file.
 * @file_to: File descriptor for destination file.
 * @arg1: First argument passed (file_from name).
 * @arg2: Second argument passed (file_to name).
 */
void check_errors(int file_from, int file_to, char *arg1, char *arg2)
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arg1);
		exit(98);
	}

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arg2);
		close(file_from);
		exit(99);
	}
}

/**
 * copy_content - Copies content from one file to another.
 * @file_from: File descriptor for source file.
 * @file_to: File descriptor for destination file.
 */
void copy_content(int file_from, int file_to)
{
	int read_status, write_status;
	char buffer[1024];

	while ((read_status = read(file_from, buffer, 1024)) > 0)
	{
		write_status = write(file_to, buffer, read_status);
		if (write_status != read_status)
		{
			dprintf(STDERR_FILENO, "Error: Can't write\n");
			close(file_from);
			close(file_to);
			exit(99);
		}
	}

	if (read_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read\n");
		close(file_from);
		exit(98);
	}
}

/**
 * main - Main function to copy content from one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, or one of the error codes on failure.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	check_errors(file_from, file_to, argv[1], argv[2]);
	copy_content(file_from, file_to);

	close(file_from);
	close(file_to);

	return (0);
}
