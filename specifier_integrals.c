#include "main.h"

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 * @num_buffer: store the number as a string
 * @countByte: keeps count of the number printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_integers(int number, char *num_buffer, int *countByte)
{
	int length;

	/* getting the length of the number in bytes */
	length = snprintf(num_buffer, UINT_SIZE, "%d", number);

	/*outputing the number like a string or character*/
	write(1, num_buffer, length);

	*countByte += length;
}
