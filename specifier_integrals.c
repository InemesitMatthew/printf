#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 * @countByte: keeps count of the number printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_integers(int number, int *countByte)
{
	int length;
	char num_buffer[UINT_SIZE]; /* Buffer stores the number as a string */

	/* getting the length of the number in bytes */
	length = snprintf(num_buffer, UINT_SIZE, "%d", number);

	/*outputing the number like a string or character*/
	write(1, num_buffer, length);

	*countByte += length;
}

/**
 * handle_binary - handle the format specifier b "%b"
 *
 * @number: number from the argument
 * @countByte: keeps count of the binary number of each digit
 * printed int bytes
 *
 * Return: void (Nothing);
 */
void handle_binary(int number, int *countByte)
{
	int binary[UINT_SIZE]; /* Array stores the binary representation */
	int i;

	i = 0;
	if (number == 0)
	{
		write(1, "0", BYTE);
		*countByte += BYTE;
	}
	else
	{
	/* Convert to binary */
		while (number > 0)
		{
			binary[i] = number % 2;
			number /= 2;
			i++;
		}

		/* Print the binary representation in reverse order*/
		for (i = (i - 1); i >= 0; i--)
		{
			/* Convert each index of binary to character */
			char digit = binary[i] + '0';

			write(1, &digit, BYTE);
			*countByte += BYTE;
		}
	}
}

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @number: unsigned integer from argument
 * @countByte: keeps count of the number of each digit, printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_unsigned_integers(unsigned int number, int *countByte)
{
	char num_buffer[UINT_SIZE];
	int length;

	length = snprintf(num_buffer, UINT_SIZE, "%u", number);

	if (length > 0)
	{
		write(1, num_buffer, length);
		*countByte += length;
	}
}
