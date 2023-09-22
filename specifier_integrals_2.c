#include <stdio.h>
#include "main.h"

/**
 * handle_lowerCase_hexadecimal - handle the format specifier x "%x"
 * to print hexadecimal representation of numbers in lower-case
 *
 * @number: number from the argument
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_lowerCase_hexadecimal(int number)
{
	char num_buffer[UINT_SIZE];
	int length;

	length = snprintf(num_buffer, sizeof(num_buffer), "%x", number);

	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_upperCase_hexadecimal - handle the format specifier X "%X"
 * to print hexadecimal representation of numbers in upper-case
 *
 * @number: number from the argument
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_upperCase_hexadecimal(int number)
{
	char num_buffer[UINT_SIZE];
	int length;

	length = snprintf(num_buffer, sizeof(num_buffer), "%X", number);

	write(1, num_buffer, length);

	return (length);
}

/**
 * handle_pointer - handles the format specifier p "%p"
 * to print memory addresses
 *
 * @ptr: pointer that stores address
 *
 * Return: The length of the printed address
 */
int handle_pointer(void *ptr)
{
	char ptr_str[UINT_SIZE]; /* Store the address as a string */
	int length;

	length = snprintf(ptr_str, sizeof(ptr_str), "%p", ptr);

	write(1, ptr_str, length); /* Output the address */

	return (length);
}

