#include "main.h"

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: void (Nothing)
 */
int handle_integers(va_list args)
{
	int length, number;
	char num_buffer[UINT_SIZE]; /* Buffer stores the number as a string */

	number = va_arg(args, int);

	/* getting the length of the number in bytes */
	length = snprintf(num_buffer, sizeof(num_buffer), "%d", number);

	/*outputing the number like a string or character*/
	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_binary - handle the format specifier b "%b"
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: void (Nothing);
 */
int handle_binary(va_list args)
{
	unsigned int binary[UINT_SIZE];
	unsigned int number; /* Array stores the binary representation */
	int i, countByte;

	number = va_arg(args, unsigned int);

	countByte = 0;

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
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: void (Nothing)
 */
int handle_unsigned_integers(va_list args)
{
	char num_buffer[UINT_SIZE];
	int length;
	unsigned int number;

	number = va_arg(args, unsigned int);

	length = snprintf(num_buffer, UINT_SIZE, "%u", number);

	if (length > 0)
		write(1, num_buffer, length);

	return (length);
}

/**
 * handle_octal - handles the format specifier o "%o"
 * to print octal representation of numbers
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed octal number
 */
int handle_octal(va_list args)
{
	char num_buffer[UINT_SIZE]; /* Stores number like a string */
	int length, number;

	number = va_arg(args, int);

	length = snprintf(num_buffer, sizeof(num_buffer), "%o", number);

	if (length > 0)
		write(1, num_buffer, length);

	return (length);
}
