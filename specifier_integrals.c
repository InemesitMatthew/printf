#include "main.h"

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 *
 * Return: void (Nothing)
 */
int handle_integers(int number)
{
	int length;
	char num_buffer[UINT_SIZE]; /* Buffer stores the number as a string */

	/* getting the length of the number in bytes */
	length = snprintf(num_buffer, UINT_SIZE, "%d", number);

	/*outputing the number like a string or character*/
	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_binary - handle the format specifier b "%b"
 *
 * @number: number from the argument
 * printed int bytes
 *
 * Return: void (Nothing);
 */
int handle_binary(int number)
{
	unsigned int binary[UINT_SIZE]; /* Array stores the binary representation */
	int i, countByte;

	countByte = 0;
	if (number < 0)
	{
		return (0);
	}

	if (number == 0)
	{
		write(1, "0", BYTE);

		return (BYTE);
	}
	else
	{
	  i = 0;
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
			countByte += BYTE;
		}

	return (countByte);
	}
}

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @number: unsigned integer from argument
 *
 * Return: void (Nothing)
 */
int handle_unsigned_integers(unsigned int number)
{
	char num_buffer[UINT_SIZE];
	int length;

	length = snprintf(num_buffer, UINT_SIZE, "%u", number);

	if (length > 0)
		write(1, num_buffer, length);

	return (length);
}

/**
 * handle_octal - handles the format specifier o "%o"
 * to print octal representation of numbers
 *
 * @number: number from the argument
 *
 * Return: The length of the printed octal number
 */
int handle_octal(int number)
{
	char num_buffer[UINT_SIZE]; /* Stores number like a string */
	int length;

	length = snprintf(num_buffer, sizeof(num_buffer), "%o", number);

	if (length > 0)
		write(1, num_buffer, length);

	return (length);
}

