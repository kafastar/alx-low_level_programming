#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_magic - Display the magic number of the ELF file
 * @e_ident: The identifier of the ELF header
 */
void display_magic(unsigned char e_ident[EI_NIDENT])
{
int i;

printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", e_ident[i]);
}
printf("\n");

}

/**
 * display_elf_header - Display the ELF header information
 * @header: Pointer to the ELF header structure
 */
void display_elf_header(Elf64_Ehdr *header)
{
	display_magic(header->e_ident);
	printf("Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s's complement, %s endian\n",
	"2", header->e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
}

/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, error code otherwise
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header of %s\n", argv[1]);
		close(fd);
		return (98);
	}

	/* Check if it's an ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_header(&header);
	close(fd);
	return (0);
}
