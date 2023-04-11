#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *magic_numbers);
void print_magic_numbers(unsigned char *magic_numbers);
void print_class(unsigned char *magic_numbers);
void print_data(unsigned char *magic_numbers);
void print_version(unsigned char *magic_numbers);
void print_os_abi(unsigned char *magic_numbers);
void print_type(unsigned int elf_type, unsigned char *magic_numbers);
void print_entry(unsigned long int entry_point, unsigned char *magic_numbers);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit with code 98.
 */
void check_elf(unsigned char *magic_numbers)
{
    for (int i = 0; i < 4; i++)
    {
        if (magic_numbers[i] != 127 && magic_numbers[i] != 'E'
            && magic_numbers[i] != 'L' && magic_numbers[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * print_magic_numbers - Prints the magic numbers of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic_numbers(unsigned char *magic_numbers)
{
    printf("  Magic:   ");

    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", magic_numbers[i]);

        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_class - Prints the class of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *magic_numbers)
{
    printf("  Class:                             ");

    switch (magic_numbers[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
    }
}

/**
 * print_data - Prints the data of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF data.
 */
void print_data(unsigned char *magic_numbers)
{
    printf("  Data:                              ");

    switch (magic_numbers[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
    }
}

/**
 * print_version - Prints the version of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *magic_numbers)
{
    printf("  Version:                           %d",
           magic_numbers[EI_VERSION]);

    switch (magic_numbers[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current

