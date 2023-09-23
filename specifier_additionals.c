#include "main.h"

/**
 * handle_upperCase_S - handle the specifier S "%S"
 *
 * @str: string from argument
 *
 * Return: Length of bytes printed out
 */
int handle_upperCase_S(char *str)
{
	int countByte;

	countByte = 0;
	while (*str)
	{
	/* A non printable character */
		if (*str <= 32 || *str >= 127)
		{
			write(1, "\\x", 2);
			countByte +=  2;

			/* Non printable hexadecimal is just a single digit so output 0 */
			if (*str < 16)
			{
				write(1, "0", BYTE);
			}

			_printf("%X", *str);
			countByte += 2;
		}
		else
		{
			/* A printable character */
			write(1, &(*str), BYTE);
			countByte++;
		}
		str++; /* Move to the next block of memory to check for the character */
	}

	return (countByte);
}
