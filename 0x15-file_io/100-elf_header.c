#include "main.h"
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * display_elf_header - Displays the information in the ELF header.
 * @ehdr: A pointer to the ELF header structure.
 */
void display_elf_header(Elf64_Ehdr *ehdr)
{
int i;  /* loop index */

    printf("ELF Header:\n");
    printf("  Magic:   ");
    /* Loop through and print magic bytes */
    for (i = 0; i < EI_NIDENT; i++)
   	    printf("%02x ", ehdr->e_ident[i]);
printf("\n");

	printf("  Class:                             ");
	printf("%s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("  Data:                              ");
	printf("%s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ?
		"2's complement, little endian" : "2's complement, big endian");

	printf("  Version:                           ");
	printf("%d (current)\n", ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	printf("UNIX - System V\n");

	printf("  ABI Version:                       ");
	printf("%d\n", ehdr->e_ident[EI_OSABI]);

	printf("  Type:                              ");
	printf("%s\n", ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
		"DYN (Shared object file)");

	printf("  Entry point address:               ");
	printf("0x%lx\n", ehdr->e_entry);
}

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 * Return: 0 on success, or 98 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		fprintf(stderr, "Error: Can't read ELF header of %s\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_header(&ehdr);
	close(fd);

	return (0);
}
