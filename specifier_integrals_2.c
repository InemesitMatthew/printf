#include "main.h"

/**
 * handle_lowerCase_hexadecimal - handle the format specifier x "%x"
 * to print hexadecimal representation of numbers in lower-case
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_lowerCase_hexadecimal(va_list args)
{
	unsigned int number;
	char num_buffer[UINT_SIZE];
	int length;

	number = va_arg(args, unsigned int);

	length = snprintf(num_buffer, sizeof(num_buffer), "%x", number);

	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_upperCase_hexadecimal - handle the format specifier X "%X"
 * to print hexadecimal representation of numbers in upper-case
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_upperCase_hexadecimal(va_list args)
{
	unsigned int number;
	char num_buffer[UINT_SIZE];
	int length;

	number = va_arg(args, int);

	length = snprintf(num_buffer, sizeof(num_buffer), "%X", number);

	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_pointer - handles the format specifier p "%p"
 * to print memory addresses
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed address
 */
int handle_pointer(va_list args)
{
	void *ptr;
	char ptr_str[UINT_SIZE]; /* Store the address as a string */
	int length;

	ptr = va_arg(args, void *);

	length = snprintf(ptr_str, sizeof(ptr_str), "%p", ptr);

	write(1, ptr_str, length); /* Output the address */

	return (length);
}
