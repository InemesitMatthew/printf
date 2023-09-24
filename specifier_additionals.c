#include "main.h"

/**
 * handle_upperCase_S - handle the specifier S "%S"
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: Length of bytes printed out
 */
int handle_upperCase_S(va_list args)
{
	int countByte;
	char *str;

	str = va_arg(args, char *);

	countByte = 0;
	while (*str)
	{
		/* A non printable character */
		if (*str < 32 || *str >= 127)
		{
			write(1, "\\x", (BYTE + BYTE)); /* Output \x */
			countByte += 2;

			/* Non printable hexadecimal is just a single digit so output 0 */
			if (*str < 16)
			{
				write(1, "0", BYTE);
			}

			_printf("%X", *str);
			countByte += (BYTE + BYTE); /* 2 characters wide */
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
