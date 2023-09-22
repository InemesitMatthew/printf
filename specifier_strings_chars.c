#include <stdio.h>
#include "main.h"

/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 *
 * Return: BYTE which is 1 for a single character
 */
int handle_char(char character)
{
	write(1, &character, BYTE);

	return (BYTE);
}

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_string(char *str_buffer)
{
	int length;

	length = strlen(str_buffer);
	if (str_buffer != NULL)
	{
		write(1, str_buffer, length);

		return (length);
	}
	else
	{
		write(1, "(null)", NULL_BYTE);

		return (NULL_BYTE);
	}
}

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 *
 * Return: BYTE which is 1 for character %
 */
int handle_percent(char character)
{
	write(1, &character, BYTE);

	return (BYTE);
}

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_reverse_string(char *str_buffer)
{
	int i, countByte;

  countByte = 0;
	/*not a null*/
	if (str_buffer != NULL)
	{

		/*get the length and minus by 1 to get the index*/
		i = strlen(str_buffer) - 1;

		while (i >= 0)
		{
			write(1, &str_buffer[i], BYTE); /*print from the last idex*/
			countByte += BYTE;
			i--;
		}

		return (countByte);
	}
	else
	{
		write(1, "(null)", NULL_BYTE); /*a null to print*/

		return (NULL_BYTE);
	}
}

/**
 * handle_rot13 - handles the format specifier R "%R"
 * to print string in rot 13 representation
 *
 * @str: string from the argument
 *
 * Return: The length of the printed rot 13 string
 */
int handle_rot13(char *str)
{
	int countByte;
	char rot_13; /* Used to hold the current conversion to rot 13 */

	/* Convert to rot13 */
	countByte = 0;
	while (*str != '\0')
	{

	if (*str >= 'A' && *str <= 'Z')
	{
	/* Convert to upper case and output */
		rot_13 = (((*str - 'A') + 13) % 26) + 'A';
	}
	else if (*str >= 'a' && *str <= 'z')
	{
	/* Convert to lower case and output */
		rot_13 = (((*str - 'a') + 13) % 26) + 'a';
	}
	else
	{
		rot_13 = *str; /* Not an alphabet so just output */
	}

	/* Control get here after each conversion so print the current character */
	write(1, &rot_13, BYTE);
	countByte += BYTE;

	str++;
	}
	return (countByte); /* Total number of character outputed */
}

