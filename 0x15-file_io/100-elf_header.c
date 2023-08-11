#include "elf.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Displays information contained in the ELF header
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (read(fd, &header, EI_NIDENT) != EI_NIDENT)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("ELF Header:\n");
	printf("  Magic: %02x %02x %02x %02x\n", header.e_ident[EI_MAG0],
	       header.e_ident[EI_MAG1], header.e_ident[EI_MAG2],
	       header.e_ident[EI_MAG3]);

	printf("  Class: %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       "2's complement, big endian");
	printf("  Version: %d\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI: %s\n", header.e_ident[EI_OSABI]);

	printf("  Type: %s\n",
	       header.e_type == ET_EXEC ? "Executable file" :
	       header.e_type == ET_DYN ? "Shared object file" :
	       header.e_type == ET_CORE ? "Core file" : "");

	printf("  Machine: %d\n", header.e_machine);
	printf("  Version: %d\n", header.e_version);

	close(fd);

	return (0);
}
