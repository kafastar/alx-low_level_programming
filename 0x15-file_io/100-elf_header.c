#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 128

void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident);
void print_data(unsigned char e_ident);
void print_version(unsigned char e_ident);
void print_os_abi(unsigned char e_ident);
void print_abi_version(unsigned char e_ident);

int main(int argc, char *argv[])
{
    int fd;
    ssize_t bytes_read;
    unsigned char e_ident[16];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
        exit(98);
    }

    bytes_read = read(fd, e_ident, sizeof(e_ident));
    if (bytes_read == -1)
    {
        fprintf(stderr, "Error: Cannot read from %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    print_magic(e_ident);
    print_class(e_ident[4]);
    print_data(e_ident[5]);
    print_version(e_ident[6]);
    print_os_abi(e_ident[7]);
    print_abi_version(e_ident[8]);

    close(fd);
    return 0;
}

void print_magic(unsigned char *e_ident)
{
    int i;
    printf("  Magic:   ");
    for (i = 0; i < 16; i++)
        printf("%02x%c", e_ident[i], (i == 15) ? '\n' : ' ');
}

void print_class(unsigned char e_ident)
{
    printf("  Class:                             ");
    switch (e_ident)
    {
        case 1: printf("ELF32\n"); break;
        case 2: printf("ELF64\n"); break;
        default: printf("<unknown>\n");
    }
}

void print_data(unsigned char e_ident)
{
    printf("  Data:                              ");
    switch (e_ident)
    {
        case 1: printf("2's complement, little endian\n"); break;
        case 2: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n");
    }
}

void print_version(unsigned char e_ident)
{
    printf("  Version:                           ");
    if (e_ident == 1)
        printf("1 (current)\n");
    else
        printf("<unknown>\n");
}

void print_os_abi(unsigned char e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident)
    {
        case 0: printf("UNIX - System V\n"); break;
        case 1: printf("HP-UX\n"); break;
        case 2: printf("NetBSD\n"); break;
        /* ... (other cases) */
        default: printf("<unknown>\n");
    }
}

void print_abi_version(unsigned char e_ident)
{
    printf("  ABI Version:                       ");
    printf("%d\n", e_ident);
}
